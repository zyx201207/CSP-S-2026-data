#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned ll;
using db = double;
using ldb = long db;

const int N = 1e6 + 5, inf = 1e9;
int c, t, n, k, res, dep[N], fa[N];
bool vis[N], v[N];
vector<int> e[N];

void init(int u, int fa) {
	dep[u] = dep[fa] + 1;
	::fa[u] = fa;
	for (int v : e[u])
		if (v != fa)
			init(v, u);
}

void dfs(int u) {
	v[u] = 1;
	for (int v : e[u])
		if (vis[v] && !::v[v])
			dfs(v);
}

int dist(int x, int y) {
	int dis = 0;
	while (x != y) {
		if (dep[x] > dep[y]) x = fa[x];
		else y = fa[y];
		++dis;
	}
	return dis;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		res = inf;
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 1, u, v; i < n; ++i) {
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		init(1, 0);
		for (int i = 1; i < (1 << n); ++i) {
			int c = 0;
			for (int j = 1; j <= n; ++j) {
				vis[j] = (i >> (j - 1)) & 1;
				if (vis[j]) ++c;
			}
			if (c > k) continue;
			int cnt = 0;
			fill(v, v + n + 1, 0);
			for (int j = 1; j <= n; ++j)
				if (vis[j] && !v[j]) {
					++cnt;
					dfs(j);
				}
//			cerr << cnt << '\n';
			if (cnt <= 2) {
//				cerr << i << '\n';
				int mx = 0;
				for (int j = 1; j <= n; ++j) {
					int ans = inf;
					for (int k = 1; k <= n; ++k)
						if (vis[k])
							ans = min(ans, dist(j, k));
//					if (i == 9) cerr << j << ' ' << ans << '\n';
					mx = max(mx, ans);
				}
//				if (mx == 1) {
//					cerr << i << '\n';
//				}
//				if (i == 1 + 8) {
//					cerr << mx << '\n';
//				}
				res = min(res, mx);
			}
		}
		cout << res << '\n';
	}
	return 0;
}
