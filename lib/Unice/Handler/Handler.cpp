//
// Created by Tica Bogdan on 14/08/2017.
//

#include "Communication/Communication.cpp"
#include "Unice/Unice.cpp"

class Handler {

protected:

    Communication *comm;

    Unice *unice;


public:

    Handler() {

        this->comm = new Communication();

        this->unice = new Unice();

    }

    void setup() {
        this->comm->connect();
    }

    void loop() {

//        if (!this->comm->checkConnection()) {
//            Serial.println();
//            Serial.println("Try to Reconnect");
//
//            this->comm->connect();
//
//        }

        //check incoming message from server
        String message;
        message = this->comm->incomingMessage();

        if (message.length() > 0) {

            this->unice->handleMessage(message);

            Serial.println("Message from Server:");
            Serial.println(message);
        }

//        this->comm->sendMessage()
//        this->comm->sendMessage("Unice Message");

        delay(1000);
    }

};