#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll c1, c2, r1, r2;
char s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> r1 >> s1 >> c2 >> r2 >> s2;
	if (c1 != c2) cout << "0000";
	else {
		cout << 1;
		if (r1 != r2) cout << "000";
		else {
			cout << 1;
			if ((s1 <= 'C' && s2 <= 'C') || (s1 >= 'D' && s2 >= 'D')) {
				cout << 1;
				if (abs(s1 - s2) == 1) cout << 1;
				else cout << "0";
			}
			else cout << "00";
	 	}
	}
	cout << endl;
	return 0;
}