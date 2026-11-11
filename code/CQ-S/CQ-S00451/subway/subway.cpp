#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <random>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;
inline int read() {int x; return scanf("%d", &x), x;}
namespace MYJBCHX
{
	const int N = 5e2;
	const int M = 5e5;
	const ll INF = 4e18;
	int n, m, q;
	int a[M + 5];
	struct edge
	{
		int v, w, ne;
	} e[M + 5];
	int h[M + 5], idx;
	inline void connect(int u, int v, int w) {e[idx] = edge{v, w, h[u]}, h[u] = idx ++ ;}
	ll dis[N + 5][N + 5];
	int main()
	{
		read(), n = read(), m = read(), read(), q = read();
		for (int i = 1; i <= m; i ++ ) a[i] = read();
		std :: memset(h, -1, sizeof h), idx = 0;
		for (int i = 1; i <= n; i ++ )
		{
			int k = read();
			while (k -- )
			{
				int u = read(), w = read();
				connect(u, i, w);
			}
		}
		std :: memset(dis, 0x3f, sizeof dis);
		for (int i = 1; i <= n; i ++ ) dis[i][i] = 0;
		for (int u = 1; u <= m; u ++ )
			for (int i = h[u]; ~i; i = e[i].ne)
			{
				int x = e[i].v, z = e[i].w;
				for (int j = e[i].ne; ~j; j = e[j].ne)
				{
					int y = e[j].v, w = e[j].w;
					dis[x][y] = dis[y][x] = std :: min(dis[x][y], (ll)(z + w));
				}
			}
		for (int k = 1; k <= n; k ++ )
			for (int i = 1; i <= n; i ++ )
				for (int j = 1; j <= n; j ++ )
					dis[i][j] = std :: min(dis[i][j], dis[i][k] + dis[k][j]);
		while (q -- )
		{
			int u = read(), v = read();
			ll res = INF;
			for (int i = h[u]; ~i; i = e[i].ne)
			{
				int x = e[i].v, z = e[i].w;
				for (int j = h[v]; ~j; j = e[j].ne)
				{
					int y = e[j].v, w = e[j].w;
					res = std :: min(res, dis[x][y] + z + w);
				}
			}
			res += a[u] + a[v];
			printf("%lld\n", res);
		}
		return 0;
	}
}
int main()
{
#ifdef LOCAL
	// freopen("in.txt", "r", stdin);
	// freopen("subway1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
	int T = 1;
	while (T -- ) MYJBCHX :: main();
	fprintf(stderr, "%.2lfs\n", std :: clock() / 1000.0);
	return 0;
}