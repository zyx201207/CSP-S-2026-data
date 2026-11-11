#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;
const ll mod = 998244353;
const ll P = 1e9 + 7;
string a, b, c, d;

int main () {
	ios :: sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);

	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);

	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << "1";
		if (b[0] == d[0] && b[1] == d[1]) {
			cout << "1";
			if ((b[2] <= 'C' && d[2] <= 'C') || 
				(b[2] >= 'D' && d[2] >= 'D')) {
				cout << "1";
				if (b[2] == 'B' || d[2] == 'B' || b[2] == 'D' || d[2] == 'D')
					cout << "1\n";
				else
					cout << "0\n";
			}
			else
				cout << "00\n";
		} else
			cout << "000\n";
	} else
		cout << "0000\n";
	return 0;
}
