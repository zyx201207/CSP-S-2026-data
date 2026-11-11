#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, ans;
int a[2000005][2];
int cnt;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> a[i][0] >> c;
		cnt += a[i][0];
		a[i][1] = c - 96;
	}
	if (cnt % 2 == 1) {
		int cnt1 = cnt;
		for (int i = n; i >= 1; i--) {
			if (cnt1 - a[i][0] <= cnt / 2) {
				a[i][0]--;
				break;
			}
			cnt1 -= a[i][0];
		}
	}
	int l = 1, r = n, ls = a[1][0], rs = a[n][0];
	while (l <= r) {
		if (a[l][1] != a[r][1]) {
			ans += min(a[r][0], a[l][0]);
		}
		if (ls < rs) {
			a[r][0] -= a[l][0];
			l++;
			ls += a[l][0];
		} else if (ls > rs) {
			a[l][0] -= a[r][0];
			r--;
			rs += a[r][0];
		} else {
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}
