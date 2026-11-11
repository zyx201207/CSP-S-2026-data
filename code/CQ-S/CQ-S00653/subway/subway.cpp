#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;
using LL = long long;
using pii = pair<int, int>;

constexpr int MAXN = 500, MAXM = 5e5, mod = 998244353;
inline void chmax(int &x, int val) { if (x < val) x = val; }
inline void chmin(int &x, int val) { if (x > val) x = val; }
inline void inc(int &x, int val) { (x += val) >= mod && (x -= mod); }
inline void dec(int &x, int val) { (x -= val) < 0 && (x += mod); }
inline void tim(int &x, int val) { (x *= val) %= mod; }

inline int qpow(int x, int y = mod - 2) {
	int res = 1;
	while (y) {
		if (y & 1) tim(res, x);
		tim(x, x), y >>= 1;
	}
	return res;	
}

int C, n, m, d, q, w[MAXM+5], f[MAXN+5][MAXN+5], tot[MAXN+5];
vector<int> a[MAXN+5], t[MAXN+5];
vector<pii> vec[MAXM+5];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	IOS;
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) f[i][j] = 1e18;
		f[i][i] = 0;
	}
	for (int i = 1, x, y; i <= n; ++i) {
		cin >> tot[i];
		for (int j = 1; j <= tot[i]; ++j) {
			cin >> x >> y;
			a[i].emplace_back(x), t[i].emplace_back(y);
			vec[x].emplace_back(i, y);
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < vec[i].size(); ++j) {
			for (int k = j + 1; k < vec[i].size(); ++k) {
				f[vec[i][j].fi][vec[i][k].fi] = f[vec[i][k].fi][vec[i][j].fi] = min(f[vec[i][j].fi][vec[i][k].fi], vec[i][j].se + vec[i][k].se);
			}
		} 
	}
	for (int k = 1; k <= n; ++k) 
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for (int x, y, ans; q--;) {
		cin >> x >> y;
		ans = LONG_LONG_MAX;
		for (auto i : vec[x]) for (auto j : vec[y]) ans = min(ans, i.se + j.se + f[i.fi][j.fi]);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
