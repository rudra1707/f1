#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESTINATION_LENGTH 30
#define MAX_DATE_LENGTH 30
#define MAX_NUMBER_OF_FLIGHTS 10

// Struct to store FlightInfo
struct FlightInfo
{
    char* destination;
    char* date;
};


// Function to fill FlightInfo with destination and date information
void fillFlightInfo(struct FlightInfo* flight, const char* destination, const char* date)
{

    // Memory allocation for destination
    (*flight).destination = (char*)malloc(strlen(destination) + 1);
    if ((*flight).destination != NULL)
    {
        // Copying destination string to allocated memory
        strcpy_s((*flight).destination, strlen(destination) + 1, destination);
    }

    // Memory allocation for date
    (*flight).date = (char*)malloc(strlen(date) + 1);
    if ((*flight).date != NULL)
    {

        // Copying data string to allocated memory
        strcpy_s((*flight).date, strlen(date) + 1, date);
    }
}


// Printing flight information
void printFlightInfo(struct FlightInfo Flights[])
{
    printf("%-35s %-35s\n", "Destination", "Date");

    for (int i = 0; i < MAX_NUMBER_OF_FLIGHTS; i++)
    {
        printf("%-35s %-35s\n", Flights[i].destination, Flights[i].date);
    }
}

// Main function
int main()
{

    // Array to store flight information
    struct FlightInfo Flights[MAX_NUMBER_OF_FLIGHTS];
    char destination[MAX_DESTINATION_LENGTH];
    char date[MAX_DATE_LENGTH];

    for (int i = 0; i < MAX_NUMBER_OF_FLIGHTS; i++)
    {

        // To get the destination from the user
        fgets(destination, sizeof(destination), stdin);


        // To get date from the user
        fgets(date, sizeof(date), stdin);


        // Removing newline character
        destination[strcspn(destination, "\n")] = '\0';

        // Removing newline character
        date[strcspn(date, "\n")] = '\0';

        fillFlightInfo(&Flights[i], destination, date);
    }

    printFlightInfo(Flights);


    // Free allocated memory
    for (int i = 0; i < MAX_NUMBER_OF_FLIGHTS; i++) {
        free(Flights[i].destination);
        free(Flights[i].date);
    }

    return 0;

}