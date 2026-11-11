#include <bits/stdc++.h>

using namespace std;

int a1, b1;
char a11, a12, a13;
char b11, b12, b13;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1;
	cin >> a11 >> a12 >> a13;
	cin >> b1;
	cin >> b11 >> b12 >> b13;
	if(a1 == b1) {
		cout << 1;
	}
	else {
		cout << "0000";
		return 0;
	}
	if(a11 == b11 && a12 == b12) {
		cout << 1;
	}
	else {
		cout << "000";
		return 0;
	}
	if(((a13 == 'A' || a13 == 'B' || a13 == 'C') && (b13 == 'A' || b13 == 'B' || b13 == 'C')) || ((a13 == 'D' || a13 == 'F') && (b13 == 'D' || b13 == 'F'))) {
		cout << 1;
	}
	else {
		cout << "00";
		return 0;
	}
	if(a13 > b13) swap(a13, b13);
	if((a13 == 'A' && b13 == 'B') || (a13 == 'B' && b13 == 'C') || (a13 == 'D' && b13 == 'F')) {
		cout << 1;
	}
	else cout << 0;
	
	return 0;
} 
