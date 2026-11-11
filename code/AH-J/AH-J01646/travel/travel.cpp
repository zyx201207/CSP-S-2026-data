#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, a1, b, b1;
	cin >> a >> a1 >> b >> b1;
	if (a == b) {
		cout << '1';
	} else {
		cout << '0' << '0' << '0' << '0';
		return 0;
	}
	if (a1[0] == b1[0] && a1[1] == b1[1]) {
		cout << '1';
	} else {
		cout << '0' << '0' << '0';
		return 0;
	}
	if ((a1[2] == 'D' && b1[2] == 'F') || (a1[2] == 'F' && b1[2] == 'D')) {
		cout << '1' << '1';
		return 0;
	} else {
		if (a1[2] >= 'A' && a1[2] <= 'C' && b1[2] >= 'A' && b1[2] <= 'C') {
			cout << '1';
		} else {
			cout << '0' << '0';
			return 0;
		}
	}
	if((a1[2] == 'A' && b1[2] == 'B') || (a1[2] == 'B' && b1[2] == 'A') || (a1[2] == 'B' && b1[2] == 'C') || (a1[2] == 'C' && b1[2] == 'B')) {
		cout << '1';
		return 0;
	} else {
		cout << '0';
		return 0;
	}
	return 0;
}
