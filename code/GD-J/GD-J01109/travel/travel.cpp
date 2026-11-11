#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3, s4;

bool pd(char ch1, char ch2) {
	if (abs(ch1 - ch2) != 1) return 0;
	if ((ch1 == 'C' && ch2 == 'D') || (ch1 == 'D' && ch2 == 'C')) return 0;
	return 1;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 != s3) cout << "0000";
	else {
		cout << "1";
		int a, b;
		a = (s2[0] - '0') * 10 + s2[1] - '0';
		b = (s4[0] - '0') * 10 + s4[1] - '0';
		if (a != b) cout << "000";
		else {
			cout << "1";
			if ((s2[2] > 'C') != (s4[2] > 'C')) cout << "00";
			else {
				cout << "1";
				if (pd(s2[2], s4[2])) cout << "1";
				else cout << '0';
			}
		}
	}
	return 0;
}
