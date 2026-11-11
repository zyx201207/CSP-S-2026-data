#include <bits/stdc++.h>
using namespace std;
int read() {
	int nu = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') {nu = nu * 10 + ch - '0'; ch = getchar();}
	return nu;
}
typedef pair<int, int> pii;
typedef long long ll;
const int maxm = 5e5 + 5;
const int maxn = 505;
const int maxd = 25;
const ll inf = 1e15;
int c, n, m, d, q, w[maxm], x, y;
vector<pii> lin_[maxm];
ll mp[maxn][maxn];
int main()  {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(); n = read(); m = read(); d = read(); q = read();
	for (int i = 1; i <= m; ++i) w[i] = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			mp[i][j] = inf;
	for (int i = 1; i <= n; ++i) mp[i][i] = 0ll;
	for (int i = 1, k; i <= n; ++i) {
		k = read();
		for (int j = 1, a, t; j <= k; ++j) {
			a = read(); t = read();
			for (auto uu : lin_[a]) {
				int vv = uu.first, tt = uu.second;
				mp[vv][i] = mp[i][vv] = min(mp[i][vv], 1ll * tt + t);
			}
			lin_[a].push_back({i, t});
		}
	}
	for (int lr = 1; lr <= n; ++lr)
		for (int uu = 1; uu <= n; ++uu)
			for (int vv = 1; vv <= n; ++vv)
				mp[uu][vv] = min(mp[uu][vv], mp[uu][lr] + mp[lr][vv]);
	while (q--) {
		x = read(); y = read();
		ll res = inf;
		for (auto uu : lin_[x]) {
			for (auto vv : lin_[y]) {
				res = min(res, mp[uu.first][vv.first] + uu.second + vv.second);
			}
		}
		printf("%lld\n", res + w[x] + w[y]);
	}
	return 0;
}

