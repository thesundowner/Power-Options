// Power Options.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;


#define CONSOLE_TEXT_COLOR_ERROR     system("color 0C")
#define CONSOLE_BACKGROUND_COLOR     system("color 0b") // aqua on black
#define TITLE                        system("title POWER OPTIONS")
#define CONSOLE_COLOR_GREEN          system("color a")
#define PAUSE                        system("pause")
#define TIMEOUT                      system("timeout /t 2 /nobreak >nul")
#define CLEAR_SCREEN                 system("cls")

void main() {
	CONSOLE_BACKGROUND_COLOR;
	TITLE;
	system("mode con: cols=42 lines=38");

	cout << endl
		<< "               POWER OPTIONS              " << endl
		<< "------------------------------------------" << endl
		<< "     [1] Shutdown PC                      " << endl
		<< "     [2] Restart PC                       " << endl
		<< "     [3] Shutdown PC(With timer)          " << endl
		<< "     [4] Restart PC(With Timer)           " << endl << endl
		<< "Choose a menu option, or write 0 to exit. " << endl;
	short option;
	cin >> option;

	if (option == 1)
	{
		CLEAR_SCREEN;
		system("title SHUTTING DOWN...");
		cout << endl << "------------------------------------------" << endl;
		cout << "GOODBYE." << endl;
		TIMEOUT;
		system("shutdown /s /t 000");

	}
	else if (option == 2)
	{
		CLEAR_SCREEN;
		system("title RESTARTING...");
		cout << endl << "------------------------------------------" << endl;
		cout << "RESTARTING..." << endl;
		TIMEOUT;
		system("shutdown /r /t 000");
	}


	else if (option == 3)
	{
		auto shutdown_t = []() {
			CLEAR_SCREEN;
			system("title SHUTDOWN TIMER");
			cout << endl << "------------------------------------------" << endl;
			cout << "Enter timer(in minutes): ";
			int timer;
			cin >> timer;
			int time_seconds = timer * 60;
			string command = "shutdown /s /t ";
			string time_str = to_string(time_seconds);
			string command_full_string = command + time_str;
			const char* full_command = command_full_string.c_str();
			system(full_command);
			CLEAR_SCREEN;
			cout << endl << "------------------------------------------" << endl;
			cout << "Your system is going to shutdown after" << timer << endl <<  "minutes." << endl
				<< "Goodbye.";
			PAUSE;
			

		};
		shutdown_t();
	}

	else if (option == 4) {
		auto restart_t = []() {
			CLEAR_SCREEN;
			system("title RESTART TIMER");
			cout << endl << "------------------------------------------" << endl;
			cout << "Enter timer(in minutes): ";
			int timer;
			cin >> timer;
			int time_seconds = timer * 60;
			string command = "shutdown /r /t ";
			string time_str = to_string(time_seconds);
			string command_full_string = command + time_str;
			const char* full_command = command_full_string.c_str();
			system(full_command);
			CLEAR_SCREEN;
			cout << endl << "------------------------------------------" << endl;
			cout << "Your system is going to restart after " << timer << endl <<  "minutes." << endl
				<< "Goodbye.";
			PAUSE;

		};

		restart_t();
	}

}
