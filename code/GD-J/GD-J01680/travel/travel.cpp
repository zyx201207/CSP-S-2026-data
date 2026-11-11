#include <bits/stdc++.h>
using namespace std;

string a , b , c , d;

int check (char c) {
	if (c == 'A') return 1;
	if (c == 'B') return 1;
	if (c == 'C') return 1;
	return 2;
}

int check1 (char c) {
	if (c == 'A') return 1;
	if (c == 'B') return 2;
	if (c == 'C') return 3;
	if (c == 'D') return 10;
	if (c == 'F') return 11;
}

int main () {
	freopen ("travel.in" , "r" , stdin);
	freopen ("travel.out" , "w" , stdout); 
	cin >> a >> b >> c >> d;
	if (a != c) {
		cout << "0000\n";
		return 0;
	}
	cout << "1";
	if (b[0] != d[0] || b[1] != d[1]) {
		cout << "000\n";
		return 0;
	}
	cout << "1";
	if (check(b[2]) != check(d[2])) {
		cout << "00\n";
		return 0;
	}
	cout << "1";
	if (abs (check1(b[2]) - check1(d[2])) != 1) cout << "0\n";
	else cout << "1\n";
	return 0;
}

