#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <list>
#include <iterator>

#include <Arduino.h>

class Configuration {
public:
  class Beacon {
  public:
    Beacon() : callsign("NOCALL-10"), message("LoRa Tracker, Info: github.com/lora-aprs/LoRa_APRS_Tracker"), timeout(1), symbol("["), overlay("/") {
    }

    String callsign;
    String message;
    int    timeout;
    String symbol;
    String overlay;
  };

  class Smart_Beacon {
  public:
    Smart_Beacon() : active(false), turn_min(25), slow_rate(300), slow_speed(10), fast_rate(60), fast_speed(100), min_tx_dist(100), min_bcn(5) {
    }

    bool active;
    int  turn_min;
    int  slow_rate;
    int  slow_speed;
    int  fast_rate;
    int  fast_speed;
    int  min_tx_dist;
    int  min_bcn;
  };

  class LoRa {
  public:
    LoRa() : frequencyRx(433775000), frequencyTx(433775000), power(20), spreadingFactor(12), signalBandwidth(125000), codingRate4(5) {
    }

    long frequencyRx;
    long frequencyTx;
    int  power;
    int  spreadingFactor;
    long signalBandwidth;
    int  codingRate4;
  };

  class PTT {
  public:
    PTT() : active(false), io_pin(4), start_delay(0), end_delay(0), reverse(false) {
    }

    bool active;
    int  io_pin;
    int  start_delay;
    int  end_delay;
    bool reverse;
  };

  class Button {
  public:
    Button() : tx(false), alt_message(false) {
    }

    bool tx;
    int  alt_message;
  };

  Configuration() : debug(false), enhance_precision(true), current_beacon_index(0) {};

  bool                debug;
  bool                enhance_precision;
  std::list<Beacon>   beacons;
  int                 current_beacon_index;
  Smart_Beacon        smart_beacon;
  LoRa                lora;
  PTT                 ptt;
  Button              button;

  Beacon GetCurrentBeacon();
  Beacon SetNextBeacon();
};

class ConfigurationManagement {
public:
  explicit ConfigurationManagement(String FilePath);

  Configuration readConfiguration();
  void          writeConfiguration(Configuration conf);

private:
  const String mFilePath;
};

#endif
