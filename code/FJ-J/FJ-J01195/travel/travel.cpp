#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
string s1, s2, x1, x2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s1 >> s2 >> x1 >> x2;
	if (s2[2] == 'F') s2[2] = 'E';
	if (x2[2] == 'F') x2[2] = 'E';
	if (s1 != x1) {
		cout << "0000";
		return 0;
	}else cout << 1;
	if (s2.substr(0, 2) != x2.substr(0, 2)) {
		cout << "000";
		return 0;
	}else cout << 1;
	if ((s2[2] <= 'C') ^ (x2[2] <= 'C')) {
		cout << "00";
		return 0;
	}else cout << 1;
	cout << (abs(s2[2] - x2[2]) == 1);
	return 0;
}

