#include<bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int n, m, ans, a[200005];
int f, vis[200005];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 31; i >= 0; i--) {
		if (!f) {
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (a[j] & (1 << i)) {
					vis[j] = 1;
					cnt++;
				}
			}
			if (cnt < m) {
				for (int j = 1; j <= n; j++) vis[j] = 0;
				continue;
			}
			f = 1;
			ans = (1 << i);
		} else {
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				if ((a[j] & (1 << i)) && vis[j]) {
					cnt++;
				}
			}
			if (cnt < m) continue;
			for (int j =  1; j <= n; j++) {
				if ((a[j] & (1 << i)) && vis[j]) vis[j] = 1;
				else vis[j] = 0;
			}
			ans += (1 << i);
		}
	}
	cout << ans;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}

