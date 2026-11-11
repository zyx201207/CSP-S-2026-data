#include <bits/stdc++.h>

using namespace std;

string a, b, c, d;

string ans = "0000";

int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	
	cin >> a >> b >> c >> d;
	if (a == c) {
		ans[0] = '1';
		if (b[0] == d[0] && b[1] == d[1]) {
			ans[1] = '1';
			if (((b[2] == 'A' || b[2] == 'C' || b[2] == 'B') && (d[2] == 'A' || d[2] == 'C' || d[2] == 'B')) || ((b[2] == 'D' || b[2] == 'F') && (d[2] == 'D' || d[2] == 'F'))) {
				ans[2] = '1';
				if (!((b[2] == 'A' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'A'))) {
					ans[3] = '1';
				}
			}
		}
	}
	cout << ans;
	return 0;
}
//Trick||Treat!
