//luogu uid: 1063589
#include <bits/stdc++.h>

//记得 long long

typedef long long ll;

const int N = 500 + 5;
const int M = 5e5 + 5;

using namespace std;

struct Edge {
	int v, w;
};

int c, n, m, d, q;
int w[M];
vector<Edge> G[M];
ll dis[N][N];

int main() {
	//地铁双向任意通行
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	//init
	memset(dis, 0x3f, sizeof dis);
	
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	
	for (int k, id, u = 1, w; u <= n; u++) {
		scanf("%d", &k);
		
		while (k--) {
			scanf("%d %d", &id, &w);
			for (auto it : G[id]) {
				int v = it.v;
				dis[u][v] = dis[v][u] = min(dis[u][v], (ll)w + it.w);
			}
			G[id].push_back({ u, w });
		}
	}
	
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			printf("dis[%d][%d] = %lld\n", i, j, dis[i][j]);
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	int x, y;
	while (q--) {
		scanf("%d %d", &x, &y);
		ll res = LLONG_MAX;
		for (auto id_x : G[x]) {
			for (auto id_y : G[y]) {
				res = min(res, dis[id_x.v][id_y.v] + id_x.w + id_y.w);
			}
		}
		printf("%lld\n", res + w[x] + w[y]);
	}
	
	return 0;
}
