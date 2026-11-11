#include<bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define ll long long

using namespace std;
const int N = 5e5 + 10;
int n, m, d, q, b[N], dis[1010][1010];
vector<pi> v[510];
bool vis[1010];

int pre[N], idx;
struct node {
	int to, next, w;
} e[2000010];

inline void add(int u, int v, int w) {
	e[++idx] = {v, pre[u], w};
	pre[u] = idx;
	e[++idx] = {u, pre[v], w};
	pre[v] = idx;
	return ;
}

inline void dijkstra(int st, int dis[]) {
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	pq.push({0, st});
	dis[st] = 0;
	while (pq.size()) {
		pi head = pq.top();
		pq.pop();
		int d = head.first, x = head.second;
		if (vis[x]) continue;
		vis[x] = true;
		for (int i = pre[x]; i; i = e[i].next) {
			int to = e[i].to;
			if (dis[to] > d + e[i].w) {
				dis[to] = d + e[i].w;
				pq.push({dis[to], to});
			}
		}
	}
	return ;
}

inline void work1() {
	for (int i = 1; i <= m; i++) {
		int l = v[i].size();
		for (int j = 0; j < l; j++)
			for (int k = j + 1; k < l; k++)
				add(v[i][j].first, v[i][k].first, v[i][j].second + v[i][k].second);
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) {
		memset(vis, false, sizeof vis);
		dijkstra(i, dis[i]);
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << dis[u][v] + b[u] + b[v] << endl; 
	}
	return ;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> m >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1, l; i <= m; i++) {
		cin >> l;
		for (int j = 1, k, w; j <= l; j++) {
			cin >> k >> w;
			v[i].push_back({k, w});
		}
	}
	if (n <= 1000) return work1(), 0;
	return 0;
}

