#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, int > pli;
#define unmp unordered_map
#define vc vector
#define pb push_back
#define FT first 
#define SD second 
#define mpr make_pair
const int N = 23 * 5e5 + 5;
const int M = 5e5 + 5;
const ll inf = 1e18;
int tot, d[N / 23], n, m, dd, qq, c;
ll dis[N], w[N / 23], ans[N / 23];
int id[N / 23][25];
int a[N / 23], t[N / 23];
bool vis[N];
vc < pair < int, ll > > g[N]; 
vc < pii > qry[N / 23];
priority_queue < pli, vc < pli >, greater < pli > > q;
void dij(int s) {
	while (!q.empty())
		q.pop();
	for (int i = 1; i <= tot; i++)
		dis[i] = inf, vis[i] = 0;
	dis[s] = 0;
	q.push(mpr(0, s));
	while (!q.empty()) {
		int u = q.top().SD;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto i : g[u]) {
			int v = i.FT;
			ll w = i.SD;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(mpr(dis[v], v));
			}
		}
	}
}
void slv1() {
	cin >> n >> m >> dd >> qq;
	for (int i = 1; i <= m; i++) {
		d[i]++; //站厅 
		tot++;
		id[i][1] = tot;
		d[i]++; //入口 
		tot++;
		id[i][2] = tot;
		d[i]++; // 出口 
		tot++;
		id[i][3] = tot;
	}
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		g[id[i][2]].pb(mpr(id[i][1], w[i]));
		g[id[i][1]].pb(mpr(id[i][3], w[i]));
	}
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++)
			cin >> a[j] >> t[j];
		for (int j = 1, u, v; j <= k; j++) {
			d[a[j]]++;
			id[a[j]][d[a[j]]] = ++tot;
			u = tot;
			v = id[a[j]][1];
			g[u].pb(mpr(v, t[j]));
			g[v].pb(mpr(u, t[j]));
		}
		for (int j = 1, u, v; j < k; j++) {
			u = id[a[j]][d[a[j]]];
			v = id[a[j + 1]][d[a[j + 1]]];
			g[u].pb(mpr(v, 0));
			g[v].pb(mpr(u, 0));
		}
	}
	for (int i = 1, u, v; i <= qq; i++) {
		cin >> u >> v;
		qry[u].pb(mpr(v, i));
	}
	for (int i = 1; i <= m; i++) {
		if (!qry[i].empty()) {
			dij(id[i][2]);
			for (auto v : qry[i])
				ans[v.SD] = dis[id[v.FT][3]];
		}
	}
	for (int i = 1; i <= qq; i++)
		cout << ans[i] << '\n';
}
int dfn[M], totd;
struct ST{
	int st[20][M], n;
	int cmp(int x, int y) {
		return (dfn[x] < dfn[y] ? x : y); 
	}
	void init(int _n) {
		n = _n;
		for (int i = 1; i < 20; i++)
			for (int j = 1; j + (1 << i) - 1 <= n; j++)
				st[i][j] = cmp(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	}
	int qry(int l, int r) {
		int len = __lg(r - l + 1);
		return cmp(st[len][l], st[len][r - (1 << len) + 1]);
	}
} St;
void dfs(int u, int pr, ll wei) {
	dfn[u] = ++totd;
	St.st[0][dfn[u]] = pr;
	dis[u] = wei;
	for (auto v : g[u]) {
		if (v.FT == pr)
			continue;
		dfs(v.FT, u, wei + v.SD);
	}
}
int lca(int x, int y) {
	if (x == y)
		return x;
	if ((x = dfn[x]) > (y = dfn[y]))
		swap(x, y);
	return St.qry(x + 1, y);
}
ll diss(int x, int y) {
	return dis[x] + dis[y] - 2 * dis[lca(x, y)];
}
void slv2() {
	cin >> n >> m >> dd >> qq;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1, k, u, v, t1, t2; i <= m; i++) {
		cin >> k;
		if (k == 1) {
			cin >> u >> t1;
			continue;
		}
		cin >> u >> t1 >> v >> t2;
		g[u].pb(mpr(1ll * t1 + t2, v));
		g[v].pb(mpr(1ll * t1 + t2, u));
	}
	dfs(1, 0, 0);
	St.init(m);
	for (int i = 1, u, v; i <= qq; i++) {
		cin >> u >> v;
		cout << w[u] + w[v] + diss(u, v);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c;
	if (c < 9)
		slv1(); 
	else if (c <= 11) 
		slv2();
	return 0;
}

