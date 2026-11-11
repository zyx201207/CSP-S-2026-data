#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	string a1, b1;
	cin >> a >> a1 >> b >> b1;
	char a2 = a1[0] + a1[1];
	char b2 = b1[0] + b1[1];
	if (a == b){
		if (a2 == b2){
			char a3 = a1[2];
			char b3 = b1[2];
			if (a3 == 'A' && b3 == 'B' || a3 == 'B' && b3 == 'A' || a3 == 'B' && b3 == 'C' || a3 == 'C' && b3 == 'B' || a3 == 'D' && b3 == 'F' || a3 == 'F' && b3 == 'D'){
				cout << 1111 <<endl; 
			}
			else if (a3 == 'A' && b3 == 'C' || a3 == 'C' && b3 == 'A'){
				cout << 1110 << endl;
			}
			else{
				cout << 1100 << endl;
			}
		}
		else{
			cout << 1000 <<endl;
		}
	}
	else{
		cout << "0000" << endl;
	}
	return 0;
} 
