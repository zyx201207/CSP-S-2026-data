#include <bits/stdc++.h>
using namespace std;
// µØÌúÕ¾ 1~m, Õ¾Ì¨ m+1 ~ 2m 

typedef long long ll;
const int M = 5e5+5, N = 505, Q = 1e5+5;

struct Edge {
	int v;
	ll w;
};
struct cmp {
	bool operator()(const Edge &x, const Edge &y) {
		return x.w > y.w;
	}
};
vector<Edge> e[M];
int a[N][M], k[N], c, n, m, d, q;
ll t[N][M];
int sum[N];

int ZhantaiId(int rt, int StationNum) {
	return 2*m + sum[StationNum-1] + rt;
}
void addEdge(int u, int v, ll w) {
	e[u].push_back((Edge){ v, w });
	e[v].push_back((Edge){ u, w });
}

ll Dijkstra(int st, int end) {
	priority_queue<Edge, vector<Edge>, cmp> q;
	bool vis[3*M];
	ll dis[3*M];
	memset(vis, false, sizeof(vis));
	memset(dis, 0ll, sizeof(dis));
	dis[st] = 0;
	q.push((Edge){ st, dis[st] });
	while (!q.empty()) {
		int now = q.top().v;
		q.pop();
		if (vis[now])
			continue;
		for (auto p : e[now]) {
			int v = p.v;
			ll w = p.w;
			if (dis[now]+w < dis[v]) {
				dis[v] = dis[now] + w;
				q.push((Edge){ v, dis[v] });
			}
		}
	}
	return dis[end];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		ll w;
		cin >> w;
		addEdge(i, m+i, w);
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		sum[i] = sum[i-1]+k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k[i]; j++) {
			addEdge(m+a[i][j], ZhantaiId(i, a[i][j]), t[i][j]);
			if (j > 1)
				addEdge(m+a[i][j-1], m+a[i][j], 0);
		}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << Dijkstra(x, y);
	}
	return 0;
}
