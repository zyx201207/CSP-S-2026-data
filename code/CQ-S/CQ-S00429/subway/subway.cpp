#include <bits/stdc++.h>
#define int long long
#define pii std::pair< int, int >
const int N = 505, M = 5e5 + 5, D = 25, inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[M], dis[N][N]; std::vector< pii > way[M];
signed main() {
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) std::cin >> w[i];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dis[i][j] = inf;
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
	for (int i = 1; i <= n; ++i) {
		int k; std::cin >> k;
		for (int j = 1, a, t; j <= k; ++j) {
			std::cin >> a >> t;
			way[a].push_back({i, t});
		}
	} for (int i = 1; i <= m; ++i) {
		for (int ti = 0; ti < (int)way[i].size(); ++ti) {
			int wi = way[i][ti].first, vi = way[i][ti].second;
			for (int tj = ti + 1; tj < (int)way[i].size(); ++tj) {
				int wj = way[i][tj].first, vj = way[i][tj].second;
				dis[wi][wj] = dis[wj][wi] = std::min(dis[wi][wj], vi + vj);
			}
		}
	}
	for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
		dis[i][j] = std::min(dis[i][k] + dis[k][j], dis[i][j]);
	for (int i = 1, u, v; i <= q; ++i) {
		std::cin >> u >> v; int A = inf;
		for (int iu = 0; iu < (int)way[u].size(); ++iu)
			for (int iv = 0; iv < (int)way[v].size(); ++iv)
				A = std::min(A, way[u][iu].second + way[v][iv].second + dis[way[u][iu].first][way[v][iv].first]);
		std::cout << A + w[u] + w[v] << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/
/*
考虑一个较为简单的暴力。对于每个地铁线路建立一个虚点，将虚点连向所有地铁线路到达的点。
这样就得到了一个 O(mq) 的暴力。
容易发现地铁线路很少，支持 O(n^3) 的 Floyd 算法，且一个站台的线路数同样很少。支持 O(md^2 + qd^2) 的算法。
那么我们考虑只保留地铁线路的虚点，在每个站台处遍历所有线路对进行建边。
时间复杂度 O(n^3 + md^2 + qd^2)，大概可以通过？ 
[15:00] 啊一遍过全部大样例？这么爽？已经拿下200了？

好像跑的有点慢啊，0.8s，不过我钦定 ccf 的机子非常快可以通过。 
哦好吧忘开 O2 了，开了直接 0.3s 飞过去了。 
*/

