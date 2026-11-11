#include <bits/stdc++.h>
#define int long long
#define USE_FREOPEN
//#define MUL_TEST
#define FILENAME "subway"
using namespace std;
typedef pair<int, int> pii;
vector<pii> stasub[500005];
int w[500005];
int G[505][505], dis[505][505], vis[505];
priority_queue<pii, vector<pii>, greater<pii> > Q;

void solve() {
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	memset(G, 0x3f, sizeof(G));
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		G[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int a, t;
			cin >> a >> t;
			for (auto it : stasub[a]) {
				int i2 = it.first, t2 = it.second;
				G[i][i2] = G[i2][i] = min(G[i][i2], t + t2);
			}
			stasub[a].push_back({i, t});
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vis[j] = 0;
		}
		
		Q.push({0, i});
		dis[i][i] = 0;
		while (Q.size()) {
			int x = Q.top().second;
			Q.pop();
			if (vis[x]) continue;
			vis[x] = 1;
			for (int j = 1; j <= n; j++) {
				if (vis[j]) continue;
				if (dis[i][j] > dis[i][x] + G[x][j]) {
					dis[i][j] = dis[i][x] + G[x][j];
					Q.push({dis[i][j], j});
				}
			}
		}
	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for (auto it : stasub[x]) {
			for (auto it2 : stasub[y]) {
				ans = min(ans, it.second + it2.second + dis[it.first][it2.first]);
			}
		}
		cout << w[x] + w[y] + ans << '\n';
	}
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
		cin >> _;
	#endif
	while (_--) solve();

	_ ^= _;
	return (0^_^0);
}

