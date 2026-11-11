#include <bits/stdc++.h>
using namespace std;
#define int long long
int path;
const int N = 2e5 + 5;
int a[N];
int f[N];
bool vis[N];
int n, m;
int ans = 0, p;
void dfs(int cnt) {
	if (cnt == m + 1) {
		ans = max(ans, p);
		return;
	}
	int old_p = p;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = 1;
		if (cnt == 1) p = a[i];
		else p &= a[i];
		dfs(cnt + 1);
		vis[i] = 0;
		p = old_p;
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (m == 1) {
		int mx = 0;
		for (int i = 1; i <= n; ++i) mx = max(mx, a[i]);
		cout << mx << '\n';
		return 0;
	}
	if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; ++i) ans &= a[i];
		cout << ans << '\n';
		return 0;
	}
	dfs(1);
	cout << ans << '\n';
	return 0;
}
