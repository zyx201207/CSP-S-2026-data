#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 10;
string a1,a2,b1,b2,ans;

signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	ans = "";
	if (a1 == b1) {
		ans += '1';
		if (a2.substr(0,2) == b2.substr(0,2)) {
			ans += '1';
			if (((a2[2] == 'A' || a2[2] == 'B' || a2[2] == 'C') && (b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C')) || (a2[2] == 'D' || a2[2] == 'E') && (b2[2] == 'D' || b2[2] == 'E')) {
				ans += '1';
				if ((a2[2] - 1 == b2[2]) || (a2[2] + 1 == b2[2])) {
					ans += '1';
				} else {
					ans += '0';
				}
			} else {
				ans += "00";
			}
		} else {
			ans += "000";
		}
	} else {
		ans += "0000";
	}
	cout << ans << endl;
	return 0;
}