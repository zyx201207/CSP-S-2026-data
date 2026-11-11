#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200005], n, m, res;
bool f[200005];

void dfs(int x, int y) {
	if (y > m) return;
	if (x > n && y != m) return;
	if (y == m && x > n) {
		int cnt = -1;
		for (int i = 1; i <= n; ++i) {
			if (!f[i]) continue;
			if (cnt == -1) cnt = a[i];
			else cnt &= a[i];
		}
		
		res = max(res, cnt);
		return;
	}
	
	f[x] = true;
	dfs(x + 1, y + 1);
	f[x] = false;
	dfs(x + 1, y);
}

void solve() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	if (n > 2000 && m != n - 1) {
		sort(a + 1, a + 1 + n, greater<int>());
		res = -1;
		for (int i = 1; i <= m; ++i) {
			if (res == -1) res = a[i];
			else res &= a[i];
		}
	}
	else dfs(1, 0);
	
	cout << res << '\n';
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	return 0;
}
