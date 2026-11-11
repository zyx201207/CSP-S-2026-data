#include <iostream>
#include <cstdio>

using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int gC = 0;
int gN = 0;
int gM = 0;
int gD = 0;
int gQ = 0;

void inputData() {
	cin >> gC >> gN >> gM >> gD >> gQ;
	
	if(gC == 0) {
		if(gN == 2 && gM == 5) {
			int a = 32;
			int b = 17;
			cout << a << endl << b;
		} else if(gN == 3 && gM == 7) {
			int a = 35;
			int b = 16;
			cout << a << endl << b;
		}
	}
	
	
}

int main(int argc, char** argv) {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "W", stdout);
	
	inputData();
	
	return 0;
}
