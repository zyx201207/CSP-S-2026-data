#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e2 + 7;
const int MAXM = 5e5 + 7;
const int MAXG = 1e5 + 7;
const int INF = 4e18;
struct node {
	int to, w;
	bool operator < (const node &x)const {
		return w > x.w;
	} 
};
struct Node {
	int a, b;
} w[MAXG];
int c, n, m, d, g, k, a, t, T;
int p[MAXM], dis[MAXN + MAXM], ans[MAXG];
bool type1 = 1;
bool vis[MAXN + MAXM];
vector<node> val[MAXM + MAXN];
void dijkstra(int x) {
	for (int i = 0; i < MAXN + MAXM; i++) dis[i] = INF;
	dis[x + m] = 0;
	memset(vis, 0, sizeof(vis));
	priority_queue<node> q;
	q.push({x + m, 0});
	vis[x + m] = 1;
	while (!q.empty()) {
		node cur = q.top();
		q.pop();
		vis[cur.to] = 0;
		for (auto u : val[cur.to]) {
			if (dis[u.to] > dis[cur.to] + u.w) {
				dis[u.to] = dis[cur.to] + u.w;
				if (!vis[u.to]) {
					vis[u.to] = 1;
					q.push({u.to, dis[u.to]});
				}
			}
		}
	}
	for (int i = 1; i <= g; i++) ans[i] = min(ans[i], dis[w[i].a] + dis[w[i].b]);
	return;
}
void bfs(int x) {
	queue<Node> q;
	q.push({x + m, 0});
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		for (auto u : val[cur.a]) {
			if (vis[u.to]) continue;
			vis[u.to] = 1;
			dis[u.to] = cur.b + 1;
			q.push({u.to, cur.b + 1});
		}
	}
	for (int i = 1; i <= g; i++) ans[i] = min(ans[i], T * (dis[w[i].a] + dis[w[i].b])); 
	return;
}
void solve() {
	for (int i = 1; i <= n; i++) bfs(i);
	for (int i = 1; i <= g; i++) {
	    ans[i] += (p[w[i].a] + p[w[i].b]);
		cout << ans[i] << "\n";
	}
	return;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> g;
	for (int i = 1; i <= m ; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			val[i + m].push_back({a, t});
			val[a].push_back({i + m, t});
			if (T != 0 && t != T) type1 = 0;
			T = t;
		}
	}	
    for (int i = 1; i <= g; i++) {
	    cin >> w[i].a >> w[i].b;
	    ans[i] = INF;
	}
	if (type1) {
		solve();
	    return 0;
	}
    for (int i = 1; i <= n; i++) dijkstra(i);
	for (int i = 1; i <= g; i++) {
		ans[i] += (p[w[i].a] + p[w[i].b]);
	    cout << ans[i] << "\n";
	}
	return 0;
}
