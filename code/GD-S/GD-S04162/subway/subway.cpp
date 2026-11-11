#include <bits/stdc++.h>
#define INF 5e14
#define ll long long

using namespace std;

const int N = 5e2 + 5;
const int M = 5e5 + 5;

bool vis[N];
ll w[M], dis[N][N], minn[N][N];
int c, n, m, d, Q, k[N];
vector<ll> t[N];
vector<int> a[N], vec[N];
vector<pair<int, int> > p[M];
priority_queue<pair<ll, int> > q;

/*
w[i] -> 第 i 个站点 进站/出站 的时间
a[x][i] -> 第 x 条线到的第 i 个站是哪个站 
t[x][i] -> 第 x 条线的第 i 个站到站台的时间 
d[x][y] -> 第 x 条线到第 y 条线的最小换乘时间
p[i] = {x, k} -> 第 i 个站点可以通过第 x 条线走过并且其在第 x 条线上的编号为 k 
*/

inline void dijkstra(int st) {
	while (q.size()) q.pop();
	for (int i = 1; i <= n; ++i) vis[i] = 0;
	
	int data = 0;
	q.push({0, st});
	
	while (q.size()) {
		if (data == n) return ;
		auto now = q.top();
		int u = now.second;
		ll cost = -now.first;
		q.pop();
		
		if (vis[u]) continue ;
		vis[u] = 1, data++;
	
		for (auto v : vec[u]) {
			if (dis[st][v] > cost + minn[u][v]) {
				dis[st][v] = cost + minn[u][v];
				q.push({-dis[st][v], v});
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ll x, y;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &Q);
	for (int i = 1; i <= m; ++i) scanf("%lld", &w[i]);
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for (int j = 1; j <= k[i]; ++j) {
			scanf("%lld%lld", &x, &y);
			a[i].push_back(x);
			t[i].push_back(y);
			p[a[i][j]].push_back({i, j});
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) dis[i][j] = minn[i][j] = INF;
		dis[i][i] = minn[i][i] = 0;
	}
	
	for (int i = 1; i <= m; ++i) {
		for (pair<int, int> u : p[i]) {
			for (pair<int, int> v : p[i]) {
				minn[u.first][v.first] 
				= minn[v.first][u.first] 
				= min(minn[u.first][v.first], t[u.first][u.second] + t[v.first][v.second]);
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (minn[i][j] == INF || i == j) continue ;
			vec[i].push_back(j);
			vec[j].push_back(i);
		}
	}
	
	for (int i = 1; i <= n; ++i) dijkstra(i);
	
	ll ans;
	for (int i = 1; i <= Q; ++i) {
		scanf("%lld%lld", &x, &y);
		ans = INF;
		
		for (auto u : p[x]) 
			for (auto v : p[y]) 
				ans = min(ans, dis[u.first][v.first] + t[u.first][u.second] + t[v.first][v.second]);
		
		printf("%lld\n", ans + w[x] + w[y]);
	}
	
	return 0;
}
