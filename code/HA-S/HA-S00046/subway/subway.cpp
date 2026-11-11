#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int INF = 0x3f3f3f3f, _INF = 0xc0c0c0c0;
const ll LLINF = 0x3f3f3f3f3f3f3f3f, _LLINF = 0xc0c0c0c0c0c0c0c0;

/*
看起来像是普通图论题。

但是你也注意到了我们不考虑在站中间穿梭的时间。

我们刚才的建模是错误的。

正确的建模是，我们把每条线看成一个节点。

然后各条线路当中有一些换乘站，可以将多条线路连接起来。

考虑我们只在图中保留换乘站和线路。

但是你又注意到换乘站可能很多。这样不能优化。

但是考虑到线路不多，我们可以先 floyd 求一下全源最短路。

但是应该也不会很多。 

你考虑全源最短路的查询是 O(1) 的。

d^2 q 能过吗？

哦，那没有任何需要担心的了。直接开始写即可。 

等会，预处理 floyd 真的没事吗？

这可能会高达 sum(k)^2!

那就比较麻烦了。考虑降到 log。

我们分线路考虑。首先枚举第一条线路，然后……不行，实际上还是那个复杂度。

哦，其实复杂度是对的？？？

好像也是 d^2 m。

那没事了。 

怎么好像假了？

不好笑。 

1.298s 是和一位？

finished 16:07 
*/

const int M = 5e5 +10, N = 510;
int c, n;
std::vector<std::pair<int, ll> > l[M];
int w[M];
int m, d, q; 
ll dis[N][N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(false); std::cin.tie(0);

	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		std::cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++) {
		int k;
		std::cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			std::cin >> a >> t;
			l[a].push_back({i, t});
		}
	}
	
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}  
	
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < l[i].size() - 1; j++) {
			for (int k = j +1; k < l[i].size(); k++) {
				auto p = l[i][j], r = l[i][k];
				dis[p.first][r.first] = std::min(dis[p.first][r.first], p.second + r.second);
				dis[r.first][p.first] = std::min(dis[r.first][p.first], p.second + r.second);
			}
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			std::cerr << dis[i][j] << ' ';
//		}
//		std::cerr << '\n';
//	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = std::min(dis[i][j], dis[i][k] +dis[k][j]);
			}
		}
	}
	
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		ll ans = w[x] +w[y];
		ll tmp = LLINF;
		for (auto &p : l[x]) {
			for (auto &r : l[y]) {
				tmp = std::min(tmp, p.second + r.second + dis[p.first][r.first]);
			}
		}
		std::cout << ans + tmp <<'\n';
	}

	return 0;
}

