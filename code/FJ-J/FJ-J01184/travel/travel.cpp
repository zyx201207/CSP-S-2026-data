#include<iostream>
using namespace std;
string a1, a2, b1, b2;
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	bool flag = true;
	for (int i = 0; i <= 1; i++) {
		if (a1[i] != b1[i]) flag = false;
	}
	if (flag) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	flag = true;
	for (int i = 0; i <= 1; i++) {
		if (a2[i] != b2[i]) flag = false;
	}
	if (flag) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	int a3, b3;
	if (a2[2] == 'D' || a2[2] == 'F') a3 = 1;
	else a3 = 2;
	if (b2[2] == 'D' || b2[2] == 'F') b3 = 1;
	else b3 = 2;
	if (a3 == b3) cout << 1;
	else {
		cout << "00";
		return 0;
	}
	if (a2[2] == 'A') a3 = 1;
	if (a2[2] == 'B') a3 = 2;
	if (a2[2] == 'C') a3 = 3;
	if (a2[2] == 'D') a3 = 5;
	if (a2[2] == 'F') a3 = 6;
	if (b2[2] == 'A') b3 = 1;
	if (b2[2] == 'B') b3 = 2;
	if (b2[2] == 'C') b3 = 3;
	if (b2[2] == 'D') b3 = 5;
	if (b2[2] == 'F') b3 = 6;
	if (a3 - b3 == -1 || a3 - b3 == 1) cout << 1;
	else cout << 0;
	return 0;
}
