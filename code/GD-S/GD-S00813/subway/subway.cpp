#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cassert>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
// #define int ll
#define OJ

constexpr int maxn = 505, maxm = 500010, maxq = 100010, maxd = 20;

int C, n, m, D, Q;
ll w[maxm];

int ln[maxn];
int cnt_id = 0;
vector<int> stats[maxn];

int deg[maxm], A[maxm][maxd], B[maxm][maxd];
ll dis[maxn][maxn];

signed main() {
#ifdef OJ
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#else
	freopen("subway7.in", "r", stdin);
	freopen("subway7.out", "w", stdout);
#endif

	cin >> C >> n >> m >> D >> Q;
	rep (i, 1, m) cin >> w[i];
	cnt_id = m;
	rep (i, 1, n) {
		cin >> ln[i];
		stats[i].clear();
		rep (j, 1, ln[i]) {
			int x; cin >> x;
			ll cost; cin >> cost;
			stats[i].push_back(x);
			A[x][deg[x]] = i, B[x][deg[x]] = cost;
			++deg[x];
		}
	}

	memset(dis, 0x3f, sizeof(dis));
	rep (i, 1, n) dis[i][i] = 0;
	rep (u, 1, m) {
		for (int j = 0; j < deg[u]; ++j)
			for (int k = 0; k < deg[u]; ++k)
				if (j != k)
					dis[A[u][j]][A[u][k]] = min(dis[A[u][j]][A[u][k]], (ll)B[u][j] + B[u][k]);
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	// rep (i, 1, n) rep (j, i + 1, n)

	rep (idq, 1, Q) {
		int s, t;
		cin >> s >> t;
		ll ans = 0x3f3f3f3f3f3f3f3fLL;
		for (int u = 0; u < deg[s]; ++u)
			for (int v = 0; v < deg[t]; ++v)
				ans = min(ans, dis[A[s][u]][A[t][v]] + B[s][u] + B[t][v]);
		ans += w[s] + w[t];
		cout << ans << '\n';
	}

	return 0;
}




