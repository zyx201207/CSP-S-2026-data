#include <bits/stdc++.h>
using namespace std;
const int maxn = 4005;
int n, k, x[maxn], y[maxn];
struct Edge {
	int to, id;
};
vector<Edge> e[maxn];
vector<int> g[maxn];
int deg[maxn], mxd[maxn], bel[maxn], d[2][maxn];
void dfs(int u, int fa, int c) {
	bel[u] = c;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if(v == fa)
			continue;
		dfs(v, u, c);
	}
}
int vis[maxn], cnt[2][maxn], res[2];
void get_solve(int k) {
	queue<int> q;
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	for (int i = 1; i <= n; i++)
		if(bel[i] == k && deg[i] <= 1)
			q.push(i), vis[i] = 1, d[k][i] = 1;
	res[k] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		res[k]++;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if(vis[v])
				continue;
			d[k][v] = max(d[k][v], d[k][u] + 1);
			deg[v]--;
			if(deg[v] == 1)
				q.push(v), vis[v] = 1;
		}
	}
}
void solve() {
	cin >> n >> k;
//	cerr << n << endl;
	for (int i = 1; i <= n; i++)
		e[i].clear(), g[i].clear();
	for (int i = 1; i < n; i++) {
		cin >> x[i] >> y[i];
		e[x[i]].push_back(Edge{y[i], i});
		e[y[i]].push_back(Edge{x[i], i});
	}
	int ans = n + 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++)
			g[j].clear();
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < e[j].size(); k++) {
				if(e[j][k].id != i)
					g[j].push_back(e[j][k].to);
			}
		}
		for (int j = 1; j <= n; j++)
			deg[j] = g[j].size(), bel[j] = 0, d[0][j] = d[1][j] = 0, cnt[0][j] = cnt[1][j] = 0;
		dfs(1, 0, 0);
		for (int j = 1; j <= n; j++) {
			if(!bel[j]) {
				dfs(j, 0, 1);
				break;
			}
		}
		get_solve(0), get_solve(1);
		for (int j = 1; j <= n; j++)
			cnt[bel[j]][d[bel[j]][j]]++;
		if(res[0] + res[1] <= k)
			ans = min(ans, 0);
//		cout << res[0] << " " << res[1] << endl;
		for (int j = 1; j <= n; j++) {
			res[0] = max(1, res[0] - cnt[0][j]);
			res[1] = max(1, res[1] - cnt[1][j]);
			if(res[0] + res[1] <= k)
				ans = min(ans, j);
		}
	}
	cout << ans << endl;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t; cin >> c >> t;
	while(t--)
		solve();
	return 0;
}
/*
1 1
6 5
1 2
2 5
4 5
5 3
3 6
*/
