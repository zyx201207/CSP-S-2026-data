#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a != c) cout << "0000";
	else {
		cout << "1";
		if (b.substr(0, 2) != d.substr(0, 2)) cout << "000";
		else {
			cout << "1";
			if ((b[2] <= 'C' && d[2] <= 'C') || (b[2] >= 'D' && d[2] >= 'D')) {
				cout << "1";
				if ((abs((int)(b[2] - d[2])) == 1) && (b[2] != 'C' || d[2] != 'D') && (b[2] != 'D' || d[2] != 'C')) cout << "1";
				else cout << "0";
			} else cout << "00";
		}
	}
	return 0;
}
