#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
const int N = 510, M = 5e5 + 10;
const int INF = 1e18;
int c, n, m, d, q, xr, yr;
int w[M];
struct Node { 
	int v, w, id;
};
vector<Node> e[N + M];
int dis[M], ans;
void dfs(int u, int fa, int id, int lst) {
	for (Node x : e[u]) {
		int v = x.v, w = x.w, id1 = x.id;
		if (v == fa) continue;
		if (id1 == id) {
			if (v <= m && dis[v] <= dis[u]) continue;
			dis[v] = min(dis[u], dis[v]); 
			if (v == yr) ans = min(ans, dis[v] + w);
			dfs(v, u, id1, w);
		} else {
			if (v <= m && dis[v] <= dis[u] + w + lst) continue;
			dis[v] = min(dis[u] + w + lst, dis[v]);
			if (v == yr) ans = min(ans, dis[v] + w);
			dfs(v, u, id1, w);
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		int k = read();
		for (int j = 1; j <= k; j++) {
			int a = read(), t = read();
			e[i + m].push_back({a, t, i});
			e[a].push_back({i + m, t, i});
		}
	}
	while (q--) {
		xr = read(), yr = read();
		for (int i = 1; i <= m + n; i++) dis[i] = INF;
		dis[xr] = 0, ans = INF;
		dfs(xr, 0, 0, 0);
		cout << ans + w[xr] + w[yr] << endl;
	}
	return 0;
}
int read() {
	int Ca = 0;
	char Cr = ' ';
	int Cf = 1;
	while (Cr < '0' || Cr > '9') {
		Cr = getchar();
		if (Cr == '-') Cf = -1;
	} 
	while (Cr >= '0' && Cr <= '9') {
		Ca = Ca * 10 + Cr - '0';
		Cr = getchar();
	}
	return Ca * Cf;
}