#include <bits/stdc++.h>
using namespace std;

string s[4];

int calc(char x) {
	if (x >= 'A' && x <= 'C') return 1;
	if (x == 'D' || x == 'F') return 2;
	return 0;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	for (int i = 0; i < 4; i++) {
		cin >> s[i];
	}
	if (s[0] != s[2]) {
		cout << "0000\n";
		return 0;
	}
	cout << "1";
	if (s[1].substr(0, 2) != s[3].substr(0, 2)) {
		cout << "000\n";
		return 0;
	}
	cout << "1";
	if (calc(s[1][2]) != calc(s[3][2])) {
		cout << "00\n";
		return 0;
	}
	cout << "1";
	if (calc(s[1][2]) == 1) {
		if (abs(s[1][2] - s[3][2]) == 1) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "1";
	}
	cout << "\n";
	return 0;
}
