#include<bits/stdc++.h>
using namespace std;

string za, zb;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	int xa, xb;
	cin >> xa >> za >> xb >> zb;
	if(xa != xb) {
		cout << "0000" << '\n';
		return 0;
	}
	else if(za[0] != zb[0] || za[1] != zb[1]) {
		cout << "1000" << '\n';
		return 0;
	}
	if((za[2] <= 'C' && zb[2] <= 'C') || (za[2] >= 'D' && zb[2] >= 'D')) {	
	}
	else {
		cout << "1100" << '\n';
		return 0;
	}
	if((za[2] == 'A' && zb[2] == 'C') || (za[2] == 'C' && zb[2] == 'A')) {
		cout << "1110" << '\n';
	}
	else {
		cout << "1111" << '\n';
	}
	return 0;
} 
