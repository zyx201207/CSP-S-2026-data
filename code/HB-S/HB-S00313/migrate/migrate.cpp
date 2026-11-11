#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e6 + 7;
int c, t, n, d, cnt, sub, ans;
int a[MAXN];
int dp[MAXN], num[MAXN];
bool type;
void solve() {
	if (cnt != 2) {
		cout << 0 << "\n";
		return;
	}
	else {
		int pos=  0;
		for (int i = 1; i <= n; i++) {
			if (a[i] - a[1] <= d && a[n] - a[i] <= d) pos = i;
		}
		if (pos == n) {
			cout << 0 << "\n";
			return;
		}
		pos++;
		for (int i = 1; i <= n; i++) {
			if (a[i] - a[1] <= d && a[n] - a[i] <= d) break;
			int l = pos, r = n, tmp = -1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (a[mid] - a[i] > d) {
					tmp = mid;
					r = mid - 1;
				} else l = mid + 1;
			}
			if (tmp == -1) continue;
			ans += (n - tmp + 1);
		}
	}
	cout << ans << "\n";
	return;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		type = 1;
		sub = cnt = ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			if (a[i] - a[1] <= d && a[n] - a[i] <= d) cnt++; 
			if (i == 2) sub = a[2] - a[1];
			if (a[i] - a[i - 1] != sub && sub != 0) type = 0;
		}
		if (cnt > 0) {
			solve();
			continue;
		}
		if (type) {
		    if (sub == 0) {
			    cout << 0 << "\n";
			    continue;
		    }
		    int y = d / sub;
		    y *= 2;
		    if (y > n || y <= 2) cout << 0 << "\n";
		    else cout << (n - y + 1) << "\n";
		    continue;
		}
		for (int i = 1; i <= n; i++) {
			memset(dp, 0, sizeof(dp));
			memset(num, 0, sizeof(num));
			dp[i] = 0;
			num[i] = 1;
			for (int j = i + 1; j <= n; j++) {
				for (int k = j - 1; k >= i; k--) {
					if (a[j] - a[k] > d) continue;
					if (dp[j] == 0 || dp[j] > dp[k] + 1) dp[j] = dp[k] + 1;
				}
				for (int k = j - 1; k >= i; k--) {
					if (a[j] - a[k] > d) break;
					if (dp[k] + 1 == dp[j]) num[j] += num[k];
				}
				if (num[j] == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

