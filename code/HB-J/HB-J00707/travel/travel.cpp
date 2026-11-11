#include <bits/stdc++.h>
using namespace std;

string a, b, c, d;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if (b[0] == d[0] && b[1] == d[1]) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	int x = b[2] - 'A' + 1, y = d[2] - 'A' + 1;
	if (x <= 3 && y >= 4 || x >= 4 && y <= 3) {
		cout << "00";
		return 0;
	}
	cout << 1;
	if (x == 1 && y == 2 || x == 2 && y == 1 || x == 2 && y == 3 || x == 3 && y == 2 || x == 4 && y == 5 || x == 5 && y == 4) cout << 1;
	else cout << 0;
	return 0;
}

