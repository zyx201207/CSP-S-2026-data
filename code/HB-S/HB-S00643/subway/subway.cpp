#include <iostream>
#include <cstring>
#include <unordered_map>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int M = 5e5 + 5;

int c, n, m, d, q;
int x, y, ans = 1e18;
bool vis[M];

unordered_map <int, int> g[M][2];
// g[i][0 / 1][j] 站厅i在第j条线路下连接的两个地铁站的编号

struct node {
	int tock; // 去出口的时间
	unordered_map <int, int> tozt; // tozt[i] 去线路i的站台的时间
} a[M]; // 站厅

void dfs(int u, int id, int t) {
	if (t >= ans) return ;
	if (u == y) {
		ans = min(ans, t + a[u].tozt[id]);
		return ;
	}
	
	// 沿着这条线路继续走
	F(i, 0, 1) {
		if (!id) continue ;
		int v = g[u][i][id];
		if (!v) continue ;
		if (vis[v]) continue ;
		dfs(v, id, t);
		vis[i] = 0;
	}
	
	// 换一条线路
	for (auto cur : a[u].tozt) {
		int nid = cur.first, nt;
		if (id == nid) continue ;
		if (id) nt = t + a[u].tozt[id] + a[u].tozt[nid];
		else nt = a[u].tozt[nid];
		dfs(u, nid, nt);
	}
	
	return ;
}

void solve() {
	ans = 1e18, memset(vis, 0, sizeof vis);
	cin >> x >> y, dfs(x, 0, 0);
	cout << ans + a[x].tock + a[y].tock << '\n';
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway1.in", "r", stdin);
	freopen("subway1.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	F(i, 1, m) cin >> a[i].tock;
	F(i, 1, n) {
		int k, lstid = 0;
		cin >> k;
		while (k--) {
			int id, t;
			cin >> id >> t;
			a[id].tozt[i] = t;
			
			g[lstid][1][i] = id;
			g[id][0][i] = lstid;
			lstid = id;
		}
	}
	
	while (q--) solve();
	
	return 0;
}
