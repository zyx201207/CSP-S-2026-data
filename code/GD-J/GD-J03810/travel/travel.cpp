#include <iostream>

using namespace std;

int cee(char s) {
	if (s == 'A' || s == 'B' || s == 'C') {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	const bool tng = c1 == c2;
	cout << (tng ? 1 : 0);
	
	const bool row = s1[0] == s2[0] && s1[1] == s2[1];
	cout << (tng && row ? 1 : 0);
	
	const bool ce = cee(s1[2]) == cee(s2[2]);
	cout << (tng && row && ce ? 1 : 0);
	
	const bool lin = abs(s1[2] - s2[2]) == 1;
	cout << (tng && row && ce && lin ? 1 : 0);
	
	cout << endl;
}
