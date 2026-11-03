
#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 10
#define TICKET_PRICE 500

// Global arrays
int seats[TOTAL_SEATS] = {0};
char passengerName[TOTAL_SEATS][50];

// Function to display available seats
void displaySeats()
{
    printf("\n------ SEAT STATUS ------\n");

    for (int i = 0; i < TOTAL_SEATS; i++)
    {
        if (seats[i] == 0)
            printf("Seat %d : Available\n", i + 1);
        else
            printf("Seat %d : Booked\n", i + 1);
    }
}

// Function to book a ticket
void bookTicket()
{
    int seat;

    printf("\nEnter seat number (1-10): ");
    scanf("%d", &seat);

    if (seat < 1 || seat > TOTAL_SEATS)
    {
        printf("Invalid seat number!\n");
    }
    else if (seats[seat - 1] == 1)
    {
        printf("Sorry! This seat is already booked.\n");
    }
    else
    {
        printf("Enter passenger name: ");
        scanf(" %49[^\n]", passengerName[seat - 1]);

        seats[seat - 1] = 1;

        printf("\nTicket booked successfully!\n");
        printf("Passenger Name: %s\n", passengerName[seat - 1]);
        printf("Seat Number: %d\n", seat);
        printf("Ticket Price: Rs. %d\n", TICKET_PRICE);
    }
}

// Function to cancel a ticket
void cancelTicket()
{
    int seat;

    printf("\nEnter seat number to cancel: ");
    scanf("%d", &seat);

    if (seat < 1 || seat > TOTAL_SEATS)
    {
        printf("Invalid seat number!\n");
    }
    else if (seats[seat - 1] == 0)
    {
        printf("This seat is not booked.\n");
    }
    else
    {
        seats[seat - 1] = 0;
        strcpy(passengerName[seat - 1], "");

        printf("Ticket cancelled successfully!\n");
    }
}

// Function to search a booking
void searchTicket()
{
    int seat;

    printf("\nEnter seat number to search: ");
    scanf("%d", &seat);

    if (seat < 1 || seat > TOTAL_SEATS)
    {
        printf("Invalid seat number!\n");
    }
    else if (seats[seat - 1] == 1)
    {
        printf("\nTicket Found!\n");
        printf("Passenger Name: %s\n", passengerName[seat - 1]);
        printf("Seat Number: %d\n", seat);
        printf("Ticket Price: Rs. %d\n", TICKET_PRICE);
    }
    else
    {
        printf("No booking found for this seat.\n");
    }
}

// Function to display all booked tickets
void displayBookings()
{
    int found = 0;

    printf("\n------ BOOKED TICKETS ------\n");

    for (int i = 0; i < TOTAL_SEATS; i++)
    {
        if (seats[i] == 1)
        {
            printf("\nPassenger: %s\n", passengerName[i]);
            printf("Seat Number: %d\n", i + 1);
            printf("Price: Rs. %d\n", TICKET_PRICE);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No tickets booked yet.\n");
    }
}

// Main function
int main()
{
    int choice;

    printf("================================\n");
    printf("   BUS TICKET RESERVATION SYSTEM\n");
    printf("================================\n");

    do
    {
        printf("\n\n========== MAIN MENU ==========\n");
        printf("1. Display Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Search a Ticket\n");
        printf("5. Display All Bookings\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displaySeats();
                break;

            case 2:
                bookTicket();
                break;

            case 3:
                cancelTicket();
                break;

            case 4:
                searchTicket();
                break;

            case 5:
                displayBookings();
                break;

            case 6:
                printf("\nThank you for using our system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
