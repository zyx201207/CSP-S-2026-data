#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 5e2 + 10;
const int MAXM = 5e5 + 10;
const long long INF = 4e18 + 10;
typedef long long LL;

struct edg {
	int v;
	LL w;
};
vector<edg> G[MAXM];

int c, n, m, d, q, a[MAXM];
LL W[MAXM], t[MAXM];

bool vis[MAXM];
LL dis[MAXM];
LL Dijkstra(int s, int tt) {
	priority_queue< pair<LL, int>, vector<pair<LL, int> >,  greater<pair<LL, int> > > PQ;
	for (int i = 1; i <= m; i++) {
		dis[i] = INF;
		vis[i] = 0;
	}
	dis[s] = 0;
	PQ.push({0, s});
	vis[s] = 1;
	while (!PQ.empty()) {
		int u = PQ.top().second;
		int disu = PQ.top().first;
		vis[u] = 1;
//		cout << disu << "\n";
		PQ.pop();
		for (auto e : G[u]) {
			int v = e.v;
			LL w = e.w;
			if (vis[v]) continue;
			if (dis[v] > disu + w) {
				dis[v] = disu + w;
				PQ.push({dis[v], v});
			}
		}
	}
//	for (int i = 1; i <= m; i++) {
//		cout << dis[i] << " ";
//	}
	return dis[tt];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf ("%lld", &W[i]);
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf ("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf ("%d%lld", &a[j], &t[j]);
		}
		for (int u = 1; u <= k; u++) {
			for (int v = 1; v <= k; v++) {
				G[a[u]].push_back({a[v], t[u] + t[v]});
				G[a[v]].push_back({a[u], t[u] + t[v]});
			}
		}
	}
	
	for (int i = 1; i <= q; i++) {
		int s, tt;
		scanf ("%d%d", &s, &tt);
		printf ("%lld\n", Dijkstra(s, tt) + W[s] + W[tt]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
