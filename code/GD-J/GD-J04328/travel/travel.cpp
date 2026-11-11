#include <bits/stdc++.h>
using namespace std;

string s1, c1, s2, c2;

bool check(char a, char b) {
	if (a == 'A' || a == 'B' || a == 'C')
		if (b == 'A' || b == 'B' || b == 'C')
			return true;
	if (a == 'D' || a == 'F')
		if (b == 'D' || b == 'F')
			return true;
	return false;
}

bool pd(char a, char b) {
	if (a == 'A' && b == 'B') return true;
	if (a == 'B' && b == 'A') return true;
	if (a == 'B' && b == 'C') return true;
	if (a == 'C' && b == 'B') return true;
	if (a == 'D' && b == 'F') return true;
	if (a == 'F' && b == 'D') return true;
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s1 >> c1 >> s2 >> c2;
	if (s1 == s2) cout << "1";
	else cout << "0";
	if (s1 == s2 && c1.substr(0, 2) == c2.substr(0, 2)) cout << "1";
	else cout << "0";
	if (s1 == s2 && c1.substr(0, 2) == c2.substr(0, 2) && check(c1[2], c2[2])) cout << "1";
	else cout << "0";
	if (s1 == s2 && c1.substr(0, 2) == c2.substr(0, 2) && check(c1[2], c2[2]) && pd(c1[2], c2[2])) cout << "1";
	else cout << "0";
	return 0;
}
