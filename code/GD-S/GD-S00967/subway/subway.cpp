#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned ll;
using db = double;
using ldb = long db;

const int N = 505, M = 5e5 + 5;
const ll inf = 2e18;
int c, n, m, d, q;
ll w[M], f[N][N];
#define pii pair<int, ll>
#define fir first
#define sec second
vector<pii> vec[M];

void chk_mn(ll &x, ll y) {
	x = min(x, y);
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int a, t;
			cin >> a >> t;
			vec[a].push_back({ i, t });
		}
	}
	memset(f, 63, sizeof f);
	for (int i = 1; i <= n; ++i) f[i][i] = 0;
	for (int i = 1; i <= m; ++i) {
		assert((int)vec[i].size() <= d);
		for (int j = 0; j + 1 < (int)vec[i].size(); ++j)
			for (int k = j + 1; k < (int)vec[i].size(); ++k) {
				ll w = vec[i][j].sec + vec[i][k].sec;
				int x = vec[i][j].fir, y = vec[i][k].fir;
				chk_mn(f[x][y], w);
				chk_mn(f[y][x], w);
			}
	}
	for (int k = 1; k <= n; ++k)
		for (int x = 1; x <= n; ++x)
			for (int y = 1; y <= n; ++y)
				f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
	for (int i = 1, x, y; i <= q; ++i) {
		cin >> x >> y;
		ll res = inf;
		for (auto a : vec[x])
			for (auto b : vec[y]) {
				ll dis = w[x] + w[y] + a.sec + b.sec + f[a.fir][b.fir];
				res = min(res, dis);
			}
		cout << res << '\n';
	}
	return 0;
}
