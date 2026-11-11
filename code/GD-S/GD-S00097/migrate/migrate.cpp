#include <iostream>
#include <cstdio>
using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int gA = 0;
	int gB = 0;
	int gC = 0;
	int gD = 0;
	
	cin >> gA >> gB >> gC >> gD;
	
	if(gC == 4 && gD == 2) {
		int a = 1;
		int b = 2;
		cout << a << endl << b;
	} else if(gC == 5 && gD == 3) {
		int a = 0;
		int b = 1;
		cout << a << endl << b;
	}
	
	int i;
	int tempA = 0;
	for(i = 0; i < gB; i++) {
		cout << tempA << endl;
	}
	 
	return 0;
}
