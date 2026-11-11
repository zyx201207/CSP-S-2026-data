#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d;
int a[2000005];
int cnt[200005];//最短路径个数 
bool f[200005];
int dp[200005];//最短路径长度 
bool Get(int l, int r) {
	for (int i = l; i <= r; i++) {
		cnt[i] = 0;
		f[i] = 0;
		dp[i] = 1e18;
	}
	dp[l] = 0;
	cnt[l] = 1;
	f[l] = 1;
	for (int i = l + 1; i <= r; i++) {
		for (int j = l; j < i; j++) {
			if (f[j] && a[i] - a[j] <= d) {
				f[i] = 1;
				if (dp[j] + 1 < dp[i]) {
					dp[i] = dp[j] + 1;
					cnt[i] = cnt[j]; 
				}				
				else if (dp[j] + 1 == dp[i]) {
					cnt[i] += cnt[j];
				}
			}
		}
		if (!f[i]) return 0;
	}
	return (cnt[r] == 2);
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		bool f = 1;
		int c = -1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1) {
				if (c = -2) {
					c = a[i] - a[i - 1];
				}
				else {
					if (a[i] - a[i - 1] != c) f = 0;
				}
			}
		}
//		cout << c << ' ' << f << '\n';
		if (f && n > 5000) {
			if (d % c == 0) {
				cout << 0 << '\n';
				continue;
			}
			if (d <= c) {
				cout << 0 << '\n';
				continue;
			}
			int base = d / c;
			int ans = 0;
			for (int i = base + 2; i <= n; i += base) {
				if (i % c == 0) continue;
				ans += n - i + 1;
			}
			cout << ans << '\n';
			continue;
		}
		int ans = 0;
//		cout << Get(1, 4) << '\n';
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (Get(i, j)) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	} 
	return 0;
}

