#include <IRremote.h>

// Piny przycisków
const int upButton = 2;
const int downButton = 3;
const int leftButton = 4;
const int rightButton = 5;
const int selectButton = 6;
const int playButton = 7;
const int stopButton = 8;

// RC-5 adres CDTV
const uint8_t deviceAddress = 0x10; // 16 dziesiętnie

// Komendy RC-5 dla CDTV
const uint8_t CMD_UP = 0x10;
const uint8_t CMD_DOWN = 0x11;
const uint8_t CMD_LEFT = 0x12;
const uint8_t CMD_RIGHT = 0x13;
const uint8_t CMD_SELECT = 0x58;
const uint8_t CMD_PLAY = 0x44;
const uint8_t CMD_STOP = 0x45;

IRsend irsend;

void setup() {
  IrSender.begin();

  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(playButton, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(upButton) == LOW) {
    sendCommand(CMD_UP);
    delay(300);
  }
  if (digitalRead(downButton) == LOW) {
    sendCommand(CMD_DOWN);
    delay(300);
  }
  if (digitalRead(leftButton) == LOW) {
    sendCommand(CMD_LEFT);
    delay(300);
  }
  if (digitalRead(rightButton) == LOW) {
    sendCommand(CMD_RIGHT);
    delay(300);
  }
  if (digitalRead(selectButton) == LOW) {
    sendCommand(CMD_SELECT);
    delay(300);
  }
  if (digitalRead(playButton) == LOW) {
    sendCommand(CMD_PLAY);
    delay(300);
  }
  if (digitalRead(stopButton) == LOW) {
    sendCommand(CMD_STOP);
    delay(300);
  }
}

void sendCommand(uint8_t command) {
  uint16_t fullCommand = (deviceAddress << 6) | (command & 0x3F);
  IrSender.sendRC5(fullCommand, 13);
}
