/*
注意 
                 m 个地铁站  
                 n 条线路 
地铁口 ->(w[v]) 站厅 ->(t[i][j]) 站台 
联通
出行计划 ：地铁口x ->(地铁) 地铁口y
可以换乘
换乘：站台 -> 站厅 -> 站台 

(d <= 20)这是关键
线路数量 n <= 500
每个地铁站的站台数量 k[i] > 0
地铁站数量 m <= 总站台数 <= 5e5
询问数量 q <= 1e5
 
 
 w 贡献只有 w[x] + w[y] 不考虑

一个站厅 最多经过 1 次 

一条线路 最多使用 1 次

   d 有什么性质呢 
   d 限制了你在一个站厅的选择
   你在一个站厅只能在这 d 条线路中选一条，并且永不回来 
	无后效性？
	如果你在起点站厅选择了其中一条线路，那你还会在途中选择其他线路吗
	显然不会，不然为什么不一开始就选另一条？
	
一个站厅 最多经过 1 次 

一条线路 最多使用 1 次

被舍弃的线路不会使用 
可以算出 dis[x][y]
 floyd
 
 15:34
 
 15:45
 做出来啦哈哈哈 
*/
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 5e5 + 5;
const int mod = 998244353;
const int inf = 0x3f3f3f3f3f3f3f3f;
int test = 1, tt = 1;
int C, n, m, d, q;
int w[N], dis[505][505], k[505];
vector<pii> v[505]; //站台 
vector<pii> e[N]; //每个站台经过的线路 
//        n 是线路数量
//        m 是地铁站数量 

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

void solve() {
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1, A, T; j <= k[i]; j++) {
			cin >> A >> T;
			v[i].emplace_back(A, T);
			e[A].emplace_back(i, T);
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		for (auto x : e[i]) {
			for (auto y : e[i]) {
				dis[x.fi][y.fi] = min(dis[x.fi][y.fi], x.se + y.se);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}
	floyd();
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (dis[i][j] >= inf) cout << "-1 ";
//			else cout << dis[i][j] << ' ';
//		}
//		cout <<'\n';
//	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = inf;
		for (auto i : e[x]) {
			for (auto j :e[y]) {
				ans = min(ans, dis[i.fi][j.fi] + i.se + j.se);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> test;
	for (; tt <= test; tt++) {
		solve();
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

