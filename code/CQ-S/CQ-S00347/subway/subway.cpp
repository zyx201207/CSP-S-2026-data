#include "iostream"
#include "algorithm"
#include "cmath"
#include "queue"
#include "vector"
#define int long long
const int N = 5e5 + 5;
const int mod = 1e9 + 7;
template <class T> inline void gmax (T &x, T y) {if (x < y) x = y;}
template <class T> inline void gmin (T &x, T y) {if (x > y) x = y;}
template <class T> inline void gadd (T &x, T y) {x = (x + y) % mod;}
template <class T> inline void gmul (T &x, T y) {x = x * y % mod;}
#define fi first
#define se second
#define pb push_back
int idx, n, m, d, q, w[N]; 
int cnt[N]; std :: pair <int, int> t[N][22]; int dis[600][600]; 
signed main () {
	freopen ("subway.in", "r", stdin); freopen ("subway.out", "w", stdout);
	std :: cin.tie (0) -> std :: ios :: sync_with_stdio (false);
	std :: cin >> idx >> n >> m >> d >> q; 
	for (int i = 1; i <= m; ++i) std :: cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k; std :: cin >> k; for (int j = 1; j <= k; ++j) {
			int x, y; std :: cin >> x >> y; t[x][++cnt[x]] = {i, y};
//			if (i == n - 1) std :: cout << x << ": " << cnt[x] << '\n';
		}
	}
//	std :: cout << t[127][1].fi << ' ' << t[127][2].fi << '\n'; 
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dis[i][j] = 1e18; for (int i = 1; i <= n; ++i) dis[i][i] = 0; 
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= cnt[i]; ++j) {
			for (int k = 1; k <= cnt[i]; ++k) { 
				gmin (dis[t[i][j].fi][t[i][k].fi], t[i][j].se + t[i][k].se); 
			}
		} 
	}
//	for (int i = 1; i <= m; ++i) {
//		std :: cout << cnt[i] << '\n';
//	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				gmin (dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			std :: cout << dis[i][j] << " \n" [j == n];
//		}
//	}
	while (q--) {
		int x, y; std :: cin >> x >> y; int ans = 1e18;
		for (int i = 1; i <= cnt[x]; ++i) {
			for (int j = 1; j <= cnt[y]; ++j) {
				gmin (ans, dis[t[x][i].fi][t[y][j].fi] + t[x][i].se + t[y][j].se); 
			}
		} std :: cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}


/*
地铁口，站厅站台到底是什么 
显然只需要考虑换乘的时间 
常规建图有平方级的边
一个点最多直接访问 20 个点？ 
不难发现，如果两个点在同一条路线中，那么就一定不会有换乘操作 
考虑 floyd
求 从 i 到 j 只需要遍包含 i，j 的所有路线中， i + j 的最小值 
wocaowo 看错题了
但这不是很简单吗？对于一条线路，只需要建立一个虚点就可以了，但是有 q 次询问怎么办
建立虚点后，图显然是一个二分图
fc mycode.out subway7.ans
*/

