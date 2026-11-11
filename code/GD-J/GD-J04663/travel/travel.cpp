// 100

#include <bits/stdc++.h>

using namespace std;

#define int long long

string c1, s1, c2, s2, ans;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) ans += "1";
	else ans += "0";
	if (c1 == c2 && s1[0] + s1[1] == s2[0] + s2[1]) ans += "1";
	else ans += "0";
	char wei1 = s1[2], wei2 = s2[2];
	if (c1 == c2 && s1[0] + s1[1] == s2[0] + s2[1] && ((wei1 <= 'C' && wei2 <= 'C') || wei1 >= 'D' && wei2 >= 'D')) {
		ans += "1";
	} else ans += "0";
	if (ans[2] == '1') {
		if (abs(wei1 - wei2) == 1) {
			ans += "1";
		} else ans += "0";
	} else ans += "0";
	cout << ans;
	return 0;
}
