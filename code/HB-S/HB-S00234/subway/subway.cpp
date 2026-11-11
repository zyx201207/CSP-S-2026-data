#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define pii pair<int,int>
using namespace std;
int c, n, t, d, q, a[505], dis[500505], u[100005], v[100005], ans[100005];
vector <pii> g[500505];
vector <int> ques[500005];

struct Node {
	int u, dis;
	friend bool operator <(Node A, Node B) {
		return A.dis > B.dis;
	}
};

void dijkstra(int i) {
	memset(dis, 0x3f, sizeof(dis));
	priority_queue <Node> q;
	dis[i] = 0;
	q.push({i, 0});
	while (!q.empty()) {
		auto tp = q.top();
		q.pop();
		int u = tp.u, dist = tp.dis;
		if (dis[u] < dist) continue;
		for (pii nxt : g[u]) {
			int v = nxt.first, w = nxt.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
	}
	for (int q : ques[i]) {
		ans[q] = dis[v[q]];
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> t >> n >> d >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= t; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, c;
			cin >> x >> c;
			g[x].push_back({n + i, c});
			g[n + i].push_back({x, c});
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> u[i] >> v[i];
		ques[u[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) if (!ques[i].empty()) {
		dijkstra(i);
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] + a[u[i]] + a[v[i]] << '\n';
	}
	return 0;
}
