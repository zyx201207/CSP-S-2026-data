#include <bits/stdc++.h>
#define int long long
#define USE_FREOPEN
#define MUL_TEST
#define FILENAME "hub"
using namespace std;
vector<int> G[1000005];
int dis[1005][1005], vis[1005];
int c;

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vis[j] = 0;
			dis[i][j] = 0;
		}
		queue<int> q;
		q.push(i);
		vis[i] = 1;
		while (q.size()) {
			int x = q.front();
			q.pop();
			for (int v : G[x]) {
				if (vis[v]) continue;
				dis[i][v] = dis[i][x] + 1;
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	int ans = 1e18;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int res = 0;
			for (int k = 1; k <= n; k++) {
				res = max(res, min(dis[i][k], dis[j][k]));
			}
			ans = min(ans, res);
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	#ifdef USE_FREOPEN
		freopen(FILENAME ".in", "r", stdin);
		freopen(FILENAME ".out", "w", stdout);
	#endif

	int _ = 1;
	#ifdef MUL_TEST
		cin >> c >> _;
	#endif
	while (_--) solve();

	_ ^= _;
	return (0^_^0);
}

