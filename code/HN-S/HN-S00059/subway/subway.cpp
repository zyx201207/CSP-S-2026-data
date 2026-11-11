/*
难道我运气真这么好？ 

发现这个 n 很好欺负的样子，可以 O(n^3 log n) 预处理两点的最短路 

然后我们有发现这个 d 很好欺负的样子，考虑 O(d^2) 枚举地铁站。

然后做完了？？？？ 
*/
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e2 + 10;
const int M = 5e5 + 10;
const int INF = 1e18;
struct edge {
	int v, w;
	friend bool operator <(const edge &x, const edge &y) {
		return x.w > y.w;
	}
}; 
vector<edge> a[N], b[M];
vector<edge> g[N];

int vis[N], dis[N][N];

void Dijkstra(int s) {
	memset(vis, 0, sizeof vis);
	priority_queue<edge> q;
	q.push({s, 0});
	dis[s][s] = 0; 
	while(q.size()) {
		int u = q.top().v; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(edge x : g[u]) {
			int v = x.v, w = x.w;
			if(dis[s][v] > dis[s][u] + w) {
				dis[s][v] = dis[s][u] + w;
				q.push({v, dis[s][v]});
			}
		} 
	} 
}

int c, n, m, d, q, w[M], cnt[N];

signed main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); // fc subway.out subway.ans 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> cnt[i];
		for(int j = 1; j <= cnt[i]; j++) {
			int x, y; cin >> x >> y;
			a[i].push_back({x, y});
			b[x].push_back({i, y});
		}
	}
	for(int u = 1; u <= n; u++) {
		for(edge x : a[u]) {
			int j = x.v, w1 = x.w;
			for(edge y : b[j]) {
				int v = y.v, w2 = y.w;
				if(u == v) continue;
				g[u].push_back({v, w1 + w2});
			}
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i++) Dijkstra(i);
	
	while(q--) {
		int s, t;
		cin >> s >> t;
		int ans = INF;
		for(edge x : b[s]) {
			for(edge y : b[t]) {
				int u = x.v, v = y.v;
				int ww = x.w + y.w;
				int sum = dis[u][v] + ww;
				ans = min(ans, sum);
			}
		} cout << ans + w[s] + w[t] << '\n';
	}
	return 0;
} 


















