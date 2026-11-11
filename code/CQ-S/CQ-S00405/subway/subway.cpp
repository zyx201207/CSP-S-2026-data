/*
luogu uid:1020627
miaomiaomiao 
*/
#include <bits/stdc++.h>
using ll = long long;
const int N = 500 + 10, M = 500000 + 10; const ll INF = 0x3f3f3f3f3f3f3f3f;
std::vector<int> vec[M];
int w[M];
ll dis[N][N];
std::map<int, int> val[N];
int c, n, m, d, q;

int32_t main() {
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	std::cin >> c >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof dis); for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) std::cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k; std::cin >> k;
		for (int j = 1; j <= k; j++) {
			int p, t; std::cin >> p >> t;
			for (int id : vec[p]) {
				ll v = std::min(dis[i][id], (ll)(t + val[id][p]));
				dis[i][id] = dis[id][i] = v;
			}
			vec[p].emplace_back(i), val[i][p] = t;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (dis[i][k] >= INF) continue;
			for (int j = i + 1; j <= n; j++) {
				ll min = std::min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[i][j] = dis[j][i] = min;
			}
		}
	}
//	for (int i = 1; i <= m; i++) std::
	for (int i = 1; i <= q; i++) {
		int u, v; ll ans = LLONG_MAX;
		std::cin >> u >> v;
		for (int a : vec[u]) {
			for (int b : vec[v]) {
//				std::cout << "!!!" << a << ' ' << b << '\n';
				ans = std::min(ans, dis[a][b] + w[u] + w[v] + val[a][u] + val[b][v]);
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}
/*
怎么又是长难句起手
啥数据范围。。 
我说是分层图有感觉吗
woc?????
注意现在只过了 16min
现在的难点是求出从 s 开始到 t 的最短路
暴力做能拿到 32pts+
我发现我不会做这个东西

发现可以转化成线路与线路的关系 
一个点最多是 20 条线路，可以 400q 的处理询问。 
考虑建图 
想到一个 dm + d^2q + n^3/2 的做法，少爷机能放我过吗
这图貌似很稠密，有点数不清 
那么开赌吧 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
跑得飞快? 
不不不他的 d 只有 2
乱造了几组极限数据，发现都过了。。。
我要拍吗，还有 2h，花 30min 写一个吧 
16.24 
不对啊，我发现他完全不需要分层
唐吧，怎么可能不分层 
没关系，全源最短路 
*/ 
