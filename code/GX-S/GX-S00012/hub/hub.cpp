#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define pre(i, n, a) for (int i = (n); i >= (a); i--)
#define pb push_back
#define eb emplace_back
#define mp std::make_pair
#define SZ(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef std::vector<int> VI;
typedef std::pair<int, int> PII;
std::mt19937 mrand(std::random_device{}());
int rnd(int x) { return mrand() % x; }
// head

struct DSU {
	VI fa, sz;
	DSU() {}
	DSU(int n) {
		// sz.assign(n + 1, 1);
		fa.resize(n + 1);
		rep(i, 1, n) fa[i] = i;
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		fa[x] = y;
		return true;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);

	std::vector<VI> adj(n + 1);
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	std::vector<VI> dist(n + 1, VI(n + 1, 1 << 30));
	rep(i, 1, n) {
		std::queue<int> q;
		q.push(i);
		dist[i][i] = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto y : adj[x]) if (dist[i][y] > dist[i][x] + 1) {
				dist[i][y] = dist[i][x] + 1;
				q.push(y);
			}
		}
	}

	int ans = 1 << 30;
	VI c(n + 1);
	auto dfs = [&](auto &&self, int x, int now) -> void {
		if (x == n + 1) {
			if (now == k) {
				DSU dsu(n);
				int remain = n;
				bool ok = true;
				int lst = 0;
				std::vector<bool> vis(n + 1);
				int tot = 0;
				rep(i, 1, n) {
					if (c[i] && !vis[i]) {
						std::queue<int> q;
						q.push(i);
						++tot;
						while (!q.empty()) {
							int x = q.front();
							q.pop();
							for (auto y : adj[x]) if (!vis[y] && c[y]) {
								vis[y] = true;
								q.push(y);
							}
						}
					}
				}
				if (tot <= 2) {
					int res = 0;
					rep(i, 1, n) {
						int mi = 1 << 30;
						rep(j, 1, n) if (c[j])
							mi = std::min(mi, dist[i][j]);
						if (c[i]) mi = 0;
						res = std::max(res, mi);
					}
					ans = std::min(ans, res);
				}
			}
			return;
		}
		if (now < k) {
			c[x] = 1;
			self(self, x + 1, now + 1);
		}
		c[x] = 0;
		self(self, x + 1, now);
	};
	dfs(dfs, 1, 0);

	printf("%d\n", ans);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	int tc, T;
	scanf("%d%d", &tc, &T);

	for (; T--; ) solve();

	return 0;
}