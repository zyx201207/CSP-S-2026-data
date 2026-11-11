#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 505, M = 500005;
const ll INF = 10000000000000000LL;

struct edge {
	int v;
	ll w;
	edge (const int & _v = 0, const ll & _w = 0) : v (_v), w (_w) {}
};

int c, n, m, d, q;
vector < edge > tf[M];
ll dis[N][N];
ll w[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", & c, & n, & m, & d, & q);
	for (int i = 1; i <= m; scanf("%lld", & w[i ++]));
	for (int i = 1, k; i <= n; ++ i) {
		scanf("%d", & k);
		for (int j = 1; j <= k; ++ j) {
			int a;
			ll t;
			scanf("%d%lld", & a, & t);
			tf[a].push_back(edge(i, t));
		}
		fill(dis[i] + 1, dis[i] + 1 + n, INF);
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; ++ i) {
		int lef = tf[i].size();
		for (int j = 0; j < lef; ++ j) {
			int v1 = tf[i][j].v;
			ll w1 = tf[i][j].w;
			for (int k = j + 1; k < lef; ++ k) {
				int v2 = tf[i][k].v;
				ll w2 = tf[i][k].w;
				dis[v1][v2] = dis[v2][v1] = w1 + w2;
			}
		}
	}
	for (int k = 1; k <= n; ++ k) {
		for (int i = 1; i <= n; ++ i) {
			if (k == i) {
				continue ;
			}
			for (int j = 1; j <= n; ++ j) {
				if (k == j || i == j) {
					continue ;
				}
				if (dis[i][k] == INF || dis[k][j] == INF) {
					continue ;
				}
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q --) {
		int x, y;
		scanf("%d%d", & x, & y);
		ll res = w[x] + w[y], mn = INF;
		for (const edge & e1 : tf[x]) {
			int v1 = e1.v;
			ll w1 = e1.w;
			for (const edge & e2 : tf[y]) {
				int v2 = e2.v;
				ll w2 = e2.w;
				mn = min(mn, dis[v1][v2] + w1 + w2);
			}
		}
		res += mn;
		printf("%lld\n", res);
	}
	return 0;
}
