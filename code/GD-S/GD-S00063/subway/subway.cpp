#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mk make_pair
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;
const int N = 5e2 + 10, inf = 1e18, M = 5e5 + 10;
int cid, n, m, D, Q, w[M], dis[N][N];
vector<pii> lns[M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> cid >> n >> m >> D >> Q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) dis[i][j] = inf;
	}
	for(int i = 1; i <= n; i++) {
		int k; cin >> k; dis[i][i] = 0;
		for(int j = 1; j <= k; j++) {
			int a, t; cin >> a >> t;
			lns[a].pb(mk(i, t));
		}
	}
	for(int i = 1; i <= m; i++) {
		int len = lns[i].size();
		for(int p = 0; p < len; p++) {
			for(int q = p + 1; q < len; q++) {
				int u = lns[i][p].fi, v = lns[i][q].fi;
				dis[u][v] = min(dis[u][v], lns[i][p].se + lns[i][q].se);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int mn = min(dis[i][j], dis[j][i]);
			dis[i][j] = dis[j][i] = mn;
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(Q--) {
		int u, v; cin >> u >> v;
		int mn = inf;
		for(pii x : lns[u]) {
			for(pii y : lns[v]) {
				mn = min(mn, dis[x.fi][y.fi] + x.se + y.se);
			}
		}
		cout << mn + w[u] + w[v] << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
