#include <bits/stdc++.h>
using namespace std;
string c, cc, s, ss, ans, tmp1, tmp2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> s >> cc >> ss;
	if (c != cc) {
		ans = "0000";
	} else {
		ans = "1";
		tmp1 = s[0] + s[1];
		tmp2 = ss[0] + ss[1];
		if (tmp1 != tmp2) {
			ans += "000";
		} else {
			ans += "1";
			if ((ss[2] < 'D' && s[2] < 'D') || (ss[2] > 'C' && s[2] > 'C')) {
				ans += "1";
				if ((ss[2] == 'D' && s[2] == 'F') || (ss[2] == 'F' && s[2] == 'D') || (abs(ss[2] - s[2]) == 1)) {
					ans += "1";
				}
				else ans += "0";
			}
			else ans += "00";
		}
	}
	cout << ans;
	return 0;	
}
