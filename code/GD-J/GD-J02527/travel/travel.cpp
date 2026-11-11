#include<iostream>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2, r1, r2;
	char z1, z2;
	cin >> c1 >> r1 >> z1 >> c2 >> r2 >> z2;
	if(c1 == c2){
		cout << "1";
		if(r1 == r2){
			cout << "1";
			if ((z1=='A' || z1=='B' || z1=='C') && (z2=='A' || z2=='B' || z2=='C')) {
				cout << "1";
				if ((z1=='B' && (z2=='A'||z2=='C')) || (z2=='B' && (z1=='A'||z1=='C')))
					cout << "1";
				else
					cout << "0";
			} else if ((z1=='D' || z1=='F') && (z2=='D' || z2=='F')) 
				cout << "11";
			else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";
	return 0;
}
