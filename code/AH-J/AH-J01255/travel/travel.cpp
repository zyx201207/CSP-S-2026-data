#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string x, y;
	for (int i = 0; i < 2; i++) {
		x = b[i];
	}
	for (int i = 0; i < 2; i++) {
		y = d[i];
	}
	int x1, y1;
	for (int i = 1; i <= 2; i++) {
		x1 = char(b[i]-'0');
	}
	for (int i = 1; i <= 2; i++) {
		y1 = char(d[i]-'0');
	}
	if (a == c) {
		cout << '1';
		if (x == y) {
			cout << '1';
		}
		else {
			cout << "000" << endl;
			return 0;
		}
		if (((x1 == 17 || x1 == 18 || x1 == 19) && (y1 == 17 || y1 == 18 || y1 == 19)) || ((1 == 20 || x1 == 21) && (y1 == 20 || y1 == 21))) {
			cout << '1';
		}
		else {
			cout << "00" << endl;
			return 0;
		}
		if (x1 - y1 == 1 || y1 - x1 == 1) {
			cout << '1';
		}
		else {
			cout << '0' << endl;
			return 0;
		}
	}
	else {
		cout << "0000" << endl;
		return 0;
	}
	return 0;
}
