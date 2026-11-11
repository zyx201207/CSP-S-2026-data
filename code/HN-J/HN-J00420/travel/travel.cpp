#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ch1 = stoi(c1), ch2 = stoi(c2);
	int z1 = stoi(s1), z2 = stoi(s2);
	char cc1 = s1.back(), cc2 = s2.back();
	cout << (ch1 == ch2) << (z1 == z2) << ((cc1 < 'D') == (cc2 < 'D')) << ((abs(cc1 - cc2) == 1) && !(cc1 == 'C' && cc2 == 'D' || cc1 == 'D' && cc2 == 'C'));
	return 0;
}

