#include <bits/stdc++.h>
#define ll long long 
using namespace std;
constexpr int N = 1005, M = 5e5 + 5;
int C, n, m, d, Q; 
int w[M], k[N], a[N][N], t[N][M];
ll dist[N][N];
bool vis[N];
int cnt, head[M];
struct edge{
	int to, nxt, id;
} e[M << 2];
struct node{
	int u;ll dis;int lst;
	bool operator < (const node &o) const {
		return dis < o.dis;
	}
};
void addedge(const int u, const int v, const int w) {
	e[++cnt].to = v;
	e[cnt].id = w;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
void solve(const int st) {
	priority_queue<node> q;
	for (int i = 1; i <= m; ++i) vis[i] = false, dist[st][i] = 1e12;
	q.push({st, 0, 0});
	dist[st][st] = 0;
	while (!q.empty()) {
		const int u = q.top().u, lst = q.top().lst;const ll val = q.top().dis;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = head[u]; i; i = e[i].nxt) {
			const int v = e[i].to, id = e[i].id;
			if (lst == 0) {
				const ll p = min(dist[st][v], val + t[id][u]);
				q.push({v, p, id});
				dist[st][v] = min(dist[st][v], p + t[id][v]);
			} else if (e[i].id == lst) {
				const ll p = min(dist[st][v], val);
				q.push({v, p, id});
				dist[st][v] = min(dist[st][v], p + t[id][v]);
			} else {
				const ll p = min(dist[st][v], val + t[lst][u] + t[id][u]);
				q.push({v, p, id});
				dist[st][v] = min(dist[st][v], p + t[id][v]);
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> C >> n >> m >> d >> Q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1, ct; j <= k[i]; ++j) {
			cin >> a[i][j] >> ct;
			t[i][a[i][j]] = ct;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 2; j <= k[i]; ++j) {
			addedge(a[i][j - 1], a[i][j], i);
			addedge(a[i][j], a[i][j - 1], i);
		} 
	}
	for (int i = 1; i <= m; ++i) {
		solve(i);
	}
	for (int i = 1; i <= Q; ++i) {
		int x, y;
		cin >> x >> y;
		cout << dist[x][y] + w[x] + w[y] << '\n';
	}
	return 0;
}

//start on 14:40; complete on 16:50; check on 18:23
