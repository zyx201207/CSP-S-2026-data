#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using cint = const int;
using cLL = const long long;
using uint = unsigned int;
using uLL = unsigned long long;

#define N 500005
#define M 505
#define base 137
#define inf 1000000007
#define mod 998244353

const double PI = acos(-1.0);

int w[N];
int k[M];
vector<pair<int, int>> node[N];

LL dis[M][M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, m, n, d, q;
	scanf("%d%d%d%d%d", &c, &m, &n, &d, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; ++j) {
			int a, t;
			scanf("%d%d", &a, &t);
			node[a].emplace_back(i, t);
		}
	}
	//
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= m; ++j)
			dis[i][j] = 1ll << 60;
		dis[i][i] = 0ll;
	}
	for (int i = 1; i <= n; ++i) { // O(Max)
		cint sz = node[i].size();
		for (int x = 0; x < sz; ++x)
			for (int y = x + 1; y < sz; ++y) {
				cint a = node[i][x].first;
				cint b = node[i][y].first;
				cLL c = node[i][x].second + node[i][y].second;
				dis[a][b] = min(dis[a][b], c);
				dis[b][a] = min(dis[b][a], c);
			}
	}
	for (int k = 1; k <= m; ++k)
		for (int i = 1; i <= m; ++i)
			if (dis[i][k] < (1ll << 60))
				for (int j = 1; j <= m; ++j)
					if (dis[k][j] < (1ll << 60))
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	//
	for (int x, y; q--; ) {
		scanf("%d%d", &x, &y);
		LL ans = 1ll << 60;
		for (auto i : node[x])
			for (auto j : node[y])
				ans = min(ans, i.second + dis[i.first][j.first] + j.second);
		printf("%lld\n", w[x] + ans + w[y]);
	}
	return 0;
}
