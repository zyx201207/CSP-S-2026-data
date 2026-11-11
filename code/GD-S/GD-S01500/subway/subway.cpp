#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int K = 5e5 + 5;
const long long LINF = 4e18;
long long a, t, c, n, m, d, q, k;
long long w[N];
long long dis[N][N];
vector<pair<int, int> > f[K];
signed main () {
	//ios::sync_with_stdio (0);
	//cin.tie (0);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			dis[i][j] = LINF;
			if (i == j) dis[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i ++) {
		cin >> k;
		for (int j = 1; j <= k; j ++) {
			cin >> a >> t;
			f[a].push_back ({i, t});
		}
	}
	for (int i = 1; i <= m; i ++) {
		for (auto x : f[i]) {
			for (auto y : f[i]) {
				if (x != y) {
					dis[x.first][y.first] = dis[y.first][x.first] = x.second + y.second;
				}
			}
		}
	}
//	for (int i = 1; i <= n; i ++) {
//		for (auto x : e[i]) cout << i << ' ' << x.first << ' ' << x.second << '\n';
//	}
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j <= n; j ++) {
//			cout << dis[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	for (int i = 1; i <= q; i ++) {
		int x, y;
		cin >> x >> y;
		long long minn = LINF;
		for (auto X : f[x]) {
			for (auto Y : f[y]) {
				minn = min (minn, dis[X.first][Y.first] + X.second + Y.second);
			}
		}
		cout << minn + w[x] + w[y] << '\n';
	}
	return 0;
} 
/*
test 1:

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


test 2:

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
/*
不是啊为什么大样例 4 5 6 都过不了
我燃尽了
ccf CCF csp CSP 114514 514114 //freopen luogu Luogu kkksc03 chen_zhe 
对我来钓鱼的

请关注锣鼓 zhao_ry514114 (uid:1117719) 谢谢喵！
请关注 codeforces 514114Zhao_ruoyi 谢谢喵！

许愿 csps 1=

下下周一（11月9日）是本喵的生日！看到这里的都要祝我生日快乐喵！ 
*/ 
