#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 510;
const int M = 5e5 + 10;
const ll inf = 1e18;
struct Edge {
	int v, w;
};
struct node {
	int v;
	ll dis;
	bool operator < (const node& x) const {
		return dis > x.dis;
	}
};
int c, n, m, d, q;
int W[M], k[N], vis[N + M];
ll dis[1510][1510], dis2[30000];
vector<Edge> e[N + M];

void dijkstra(int s) {
	for (int i = 1; i <= n + m; i++) dis[s][i] = inf, vis[i] = 0;
	dis[s][s] = 0;
	priority_queue<node> pq;
	pq.push({s, 0});
	while (!pq.empty()) {
		node t = pq.top(); pq.pop();
		if (vis[t.v]) continue;
		vis[t.v] = 1;
		for (Edge tmp : e[t.v]) {
			int v = tmp.v, w = tmp.w;
			if (dis[s][v] > dis[s][t.v] + w) {
				dis[s][v] = dis[s][t.v] + w;
				if (!vis[v]) pq.push({v, dis[s][v]});
			}
		}
	}
}

void dijkstra2(int s) {
	for (int i = 1; i <= n + m; i++) dis2[i] = inf, vis[i] = 0;
	dis2[s] = 0;
	priority_queue<node> pq;
	pq.push({s, 0});
	while (!pq.empty()) {
		node t = pq.top(); pq.pop();
		if (vis[t.v]) continue;
		vis[t.v] = 1;
		for (Edge tmp : e[t.v]) {
			int v = tmp.v, w = tmp.w;
			if (dis2[v] > dis2[t.v] + w) {
				dis2[v] = dis2[t.v] + w;
				if (!vis[v]) pq.push({v, dis2[v]});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%d", &W[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++) {
			int v, w;
			scanf("%d%d", &v, &w);
			e[i].push_back({v + n, w});
			e[v + n].push_back({i, w});
		}
	}
	if (m > 1000) {
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			dijkstra2(n + x);
			printf("%lld\n", dis2[y + n] + W[x] + W[y]);
		}
		return 0;
	}
	for (int i = n + 1; i <= n + m; i++) dijkstra(i);
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", dis[x + n][y + n] + W[x] + W[y]);
	}
	return 0;
}
