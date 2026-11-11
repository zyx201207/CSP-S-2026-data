#include <bits/stdc++.h>
using namespace std;
int c1, c2, l1, l2;
char a, b;
string s1, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	l1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	l2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	a = s1[2];
	b = s2[2];
	if (c1 == c2) {
		cout << '1';
		if (l1 == l2) {
			cout << '1';
			if ((a <= 'C' && b <= 'C') || (a > 'C' && b > 'C')) {
				cout << '1';
				if (abs((a - 'A') - (b - 'A')) == 1 || (a > 'C' && b > 'C')) {
					cout << '1';
				}
				else {
					cout << '0';
				}
			}
			else {
				cout << "00";
			}
		}
		else {
			cout << "000";
		}
	}
	else {
		cout << "0000";
	}
	return 0;
}
