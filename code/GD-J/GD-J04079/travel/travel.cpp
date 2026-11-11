#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, ans = "0000";
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		ans[0] = '1';
		string l1 = "", l2 = "";
		l1 += s1[0], l2 += s2[0];
		l1 += s1[1], l2 += s2[1];
		if (l1 == l2) {
			ans[1] = '1';
			if ((s1[2] <= 'C' && s2[2] <= 'C') || s1[2] >= 'D' && s2[2] >= 'D') {
				ans[2] = '1';
				if (abs(s2[2] - s1[2]) == 1 && (s2[2] != 'D' || s1[2] != 'C') && (s1[2] != 'C' || s2[2] != 'D'))
					ans[3] = '1', cout << ans;
				else
					cout << ans;
			}
			else
				cout << ans;
		}
		else
			cout << ans;
	}
	else
		cout << ans;
	return 0;
}