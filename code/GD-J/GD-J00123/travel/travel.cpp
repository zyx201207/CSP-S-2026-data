#include <bits/stdc++.h>
using namespace std;
string c1, c2, c3, c4;
int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	int a = (c1[1] - '0') + (c1[0] - '0') * 10;
	int b = (c2[1] - '0') + (c2[0] - '0') * 10;
	int c = (c3[1] - '0') + (c3[0] - '0') * 10;
	int d = (c4[1] - '0') + (c4[0] - '0') * 10;
//	printf ("%d %d %d %d", a, b, c, d); 
	if (a == c) {
		cout << 1;
	}
	else {
		cout << "0000";
		return 0;
	}
	if (b == d) {
		cout << 1;
	}
	else {
		cout << "000";
		return 0;
	}
	if (c2[2] <= 'C' && c4[2] <= 'C' || c2[2] > 'C' && c4[2] > 'C') {
		cout << 1;
	}
	else {
		cout << "00";
		return 0;
	}
	if (c2[2] + 1 == c4[2] || c4[2] + 1 == c2[2]) {
		cout << 1;
	}
	else {
		cout << "0";
		return 0;
	}
	
	return 0;
} 
