#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
const long long inf = 0x3f3f3f3f3f3f;
int C, n, m, D, Q, vis[505];
long long g[505][505], ans, W[N];
struct node { int a; long long t; };
vector <node> a[505];
vector <node> b[N];

int head[505], cnt;
struct Edge { int to; long long w; int next; } e[N];
inline void AddEdge (int u, int v, int w) {
	e[++cnt] = {v, w, head[u]};
	head[u] = cnt;
}

priority_queue <pair<long long, int>> q;

signed main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> C >> n >> m >> D >> Q;
	for (int i = 1; i <= m; ++i) cin >> W[i];
	for (int i = 1, k; i <= n; ++i) {
		cin >> k;
		for (int j = 0; j < k; ++j) a[i].push_back ({0, 0});
		for (int j = 0; j < k; ++j) {
			cin >> a[i][j].a >> a[i][j].t;
			b[a[i][j].a].push_back ({i, a[i][j].t});
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) g[i][j] = inf;
		g[i][i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < a[i].size (); ++j) {
			int u = a[i][j].a, t = a[i][j].t;
			for (int k = 0; k < b[u].size (); ++k) {
				int v = b[u][k].a, t2 = b[u][k].t;
				if (g[i][v] > t + t2) g[i][v] = g[v][i] = t + t2;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (g[i][j] == inf) continue;
//			cout << " > " << i << " " << j << " : " << g[i][j] << '\n';
			AddEdge (i, j, g[i][j]);
			AddEdge (j, i, g[i][j]); 
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) g[i][j] = inf, vis[j] = 0;
		g[i][i] = 0; q.push ({0, i});
		while (!q.empty ()) {
			long long dis = - q.top ().first; int u = q.top ().second; q.pop ();
			if (vis[u]) continue; vis[u] = 1;
			for (int j = head[u]; j; j = e[j].next) {
				int v = e[j].to, w = e[j].w;
				if (vis[v]) continue;
				if (g[i][v] > dis + w) {
					g[i][v] = dis + w;
					q.push ({-g[i][v], v});
				}
			}
		}
//		for (int j = 1; j <= n; ++j) {
//			if (g[i][j] != inf) cout << " - " << i << " " << j << " : " << g[i][j] << '\n';
//		}
	}
	while (Q--) {
		int u, v; ans = inf;
		cin >> u >> v;
		for (int i = 0; i < b[u].size (); ++i) {
			int x = b[u][i].a, t = b[u][i].t + W[u];
			for (int j = 0; j < b[v].size (); ++j) {
				int y = b[v][j].a, t2 = b[v][j].t + W[v];
				ans = min (ans, t + t2 + g[x][y]);
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
