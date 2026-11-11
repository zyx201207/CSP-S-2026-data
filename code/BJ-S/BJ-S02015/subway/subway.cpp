#include <bits/stdc++.h>
using namespace std;

#define DEBUG
#ifdef DEBUG
#define dbg(x) ({auto __V = (x); cout << __V << endl; __V;})
#define dbg_end(x, S) ({auto __V = (x); cout << __V << (S); __V;})
#else
#define dbg(x) x
#define dbg_end(x, S) x
#endif

#define ll long long
#define ull unsigned long long

const int MAXN = 505, MAXM = 500005;

struct edge {
	int v;
	ll t;

	bool operator>(const edge &e) const {
		return t > e.t;
	}
};

int c, n, m, d, Q;
int w[MAXM];
vector<edge> routes[MAXN];
map<int, int> passby[MAXM];

ll dis[MAXM];
bool vis[MAXM];
priority_queue<edge, vector<edge>, greater<edge>> q;

struct question {
	int u, v, n;
	ll ans;
};

question qs[100005];

void dijkstra(int start) {
	for (int i = 0; i <= m; i++)
		dis[i] = 1ll << 62, vis[i] = 0;
	dis[start] = 0;
	q.push({start, 0});
	while (!q.empty()) {
		edge node = q.top();
		q.pop();
		if (vis[node.v])
			continue;
		vis[node.v] = 1;
		for (auto _route : passby[node.v]) {
			int route = _route.first;
			int nodet = _route.second;
			for (auto e : routes[route]) {
				if (vis[e.v])
					continue;
				ll nv = dis[node.v] + nodet + e.t;
 				if (dis[e.v] > nv) {
					dis[e.v] = nv;
					q.push({e.v, nv});
 				}
			}
		}
		// for (int i = 1; i <= m; i++)
		// 	printf("%lld ", dis[i]);
		// puts("");
		// for (int i = 1; i <= m; i++)
		// 	printf("%d ", vis[i]);
		// puts("");
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &Q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		int _;
		scanf("%d", &_);
		for (int j = 0; j < _; j++) {
			edge e;
			scanf("%d%lld", &e.v, &e.t);
			routes[i].push_back(e);
			passby[e.v][i] = e.t;
		}
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &qs[i].u, &qs[i].v);
		if (qs[i].u > qs[i].v)
			swap(qs[i].u, qs[i].v);
		qs[i].n = i;
	}
	sort(qs, qs + Q, [](const question &a, const question &b) { return a.u < b.u; });
	for (int i = 0; i < Q; i++) {
		if (i == 0 || qs[i].u != qs[i - 1].u)
			dijkstra(qs[i].u);
		qs[i].ans = dis[qs[i].v] + w[qs[i].u] + w[qs[i].v];
	}
	sort(qs, qs + Q, [](const question &a, const question &b) { return a.n < b.n; });
	for (int i = 0; i < Q; i++) {
		printf("%lld\n", qs[i].ans);
	}
	return 0;
}
