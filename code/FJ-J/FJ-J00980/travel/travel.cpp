#include <bits/stdc++.h>
using namespace std;

int x, y;
string a, b, c, d;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	x = b[2] - 'A' + 1;
	y = d[2] - 'A' + 1;
	if (b[2] == 'F') x--;
	if (d[2] == 'F') y--;
	if (a == c) {
		cout << 1;
		if (b[0] == d[0] && b[1] == d[1]) {
			cout << 1;
			if ((x < 4 && y < 4) || (x > 3 && y > 3)) {
				cout << 1;
				if (abs(x - y) == 1) cout << 1;
				else cout << 0;
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}
