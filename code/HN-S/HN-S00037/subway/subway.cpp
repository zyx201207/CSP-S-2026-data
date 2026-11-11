#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6 + 10;
const ll inf = 1e18;

struct Edge2 {
	int x, y;
	ll w;
} edge[N];

struct qy {
	int x, y, id;
} qu[N];

struct Edge {
	int v;
	ll w;
	
	bool operator < (const Edge &x) const {
		return w > x.w;
	}
};
int eg, nd, d, q, weight[N], m;
vector<Edge> e[N], g[N];
ll dis[N], ans[N];
bool vis[N];

void addedge(int x, int y, int w) {
	e[x].push_back({y, w});
	e[y].push_back({x, w});
	edge[++m] = {x, y, w};
}

bool cmp(qy A, qy B) {
	return A.x < B.x;
}

void dij(int S) {
	for (int i = 1; i <= nd + eg + 1; i++) dis[i] = inf, vis[i] = 0;
	
	priority_queue<Edge> pq;
	pq.push({S, 0});
	dis[S] = 0;
	
	while (!pq.empty()) {
		int u = pq.top().v;
		pq.pop();
		
		if (vis[u]) continue;
		vis[u] = 1;
		
		for (auto tmp : e[u]) {
			int v = tmp.v;
			ll w = tmp.w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (vis[v]) continue;
				pq.push({v, dis[v]});
			}
		} 
	}
}

void sol1() {
	for (int i = 1; i <= q; i++) 
		if (qu[i].x > qu[i].y) swap(qu[i].x, qu[i].y);
	sort(qu + 1, qu + 1 + q, cmp);
	
	for (int T = 1; T <= q; T++) {
		int st = qu[T].x, ed = qu[T].y, id = qu[T].id;
		if (T == 1 || st != qu[T - 1].x) dij(st);
		
		ans[id] = (ll)weight[st] + dis[ed] + (ll)weight[ed];
	}
	
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}

bool cmp2(Edge2 A, Edge2 B) {
	return A.w < B.w;
}

int F[N];

int find(int x) {
	if (F[x] != x) F[x] = find(F[x]);
	return F[x];
}

void kruskal() {
	for (int i = 1; i <= nd + eg; i++) F[i] = i;
	sort(edge + 1, edge + 1 + m, cmp2);
	
	int nedge = 0;
	for (int i = 1; i <= m; i++) {
		int u = edge[i].x, v = edge[i].y;
		ll w = edge[i].w;
		
		int r1 = find(u), r2 = find(v);
		if (r1 == r2) continue;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		
		nedge++;
		
		if (nedge == nd + eg - 1) break;
	}
}

int siz[N], fa[N], top[N], dep[N], son[N];
ll dp[N];

void dfs1(int u, int f) {
	siz[u] = 1;
	dep[u] = dep[f] + 1;
	fa[u] = f;
	
	for (auto tmp : g[u]) {
		int v = tmp.v;
		ll w = tmp.w;
		if (v != f) {
			dp[v] = dp[u] + w;
			dfs1(v, u);
			siz[u] += siz[v];
			
			if (siz[son[u]] < siz[v]) son[u] = v;
		}
	}
}

void dfs2(int u, int f) {
//	cout <<u <<endl;
	top[u] = f;
	
	if (!son[u]) return;
	dfs2(son[u], f);
	
	for (auto tmp : g[u]) {
		int v = tmp.v;
		ll w = tmp.w;
//		cout <<v <<endl;
		if (v != fa[u] && v != son[u]) {
//			dp[v] = dp[u] + w;
			dfs2(v, v);
		}
	}
}

int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	
	if (dep[x] < dep[y]) return x;
	return y;
}

void sol2() {
	kruskal();
	
	dfs1(1, 0);
	dfs2(1, 1);
	
//	for (int i = 1; i <= nd + eg; i++) cout <<dp[i] <<" ";
	
	for (int T = 1; T <= q; T++) {
		int st = qu[T].x, ed = qu[T].y, id = qu[T].id;
		ans[T] = (ll)weight[st] + (ll)weight[ed];
		
		int l = lca(st, ed);
		ans[T] += dp[st] + dp[ed] - 2 * dp[l];
	}
	
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c;
	cin >> c >> eg >> nd >> d >> q; 
	for (int i = 1; i <= nd; i++) cin >> weight[i]; 
	for (int i = 1; i <= eg; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, y;
			cin >> x >> y;
			addedge(x, nd + i, y);
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> qu[i].x >> qu[i].y; 
		qu[i].id = i; 
	}
	
	if ((nd + eg) * q <= 1e8) sol1();
	else sol2();

	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
