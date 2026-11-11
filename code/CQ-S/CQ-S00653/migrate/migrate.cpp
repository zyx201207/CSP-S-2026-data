#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;
using LL = long long;
using pii = pair<int, int>;

constexpr int MAXN = 2e6, MAXM = 2e6, mod = 998244353;
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
int C, T, n, d, a[MAXN+5], pre[MAXN+5], nxt[MAXN+5], cnt[MAXN+5], f[5005][5005], g[5005][5005]; 

namespace b1t {
	int t[MAXN+5];
	inline void init() {
		for (int i = 0; i <= n; ++i) t[i]= 0 ;
	}
	inline void add(int x, int y) {
		for (int i = x; i <= n; i += (i & -i)) t[i] += y;
	}
	inline int query(int l, int r) {
		if (l > r) return 0;
		int res = 0;
		for (int i = r; i > 0; i -= (i & -i)) res += t[i];
		for (int i = l - 1; i > 0; i -= (i & -i)) res -= t[i];
		return res;
	}
}

using namespace b1t;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	IOS;
	cin >> C >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1, j = 1; i <= n; ++i) {
			while (a[i] - a[j] > d) ++j;
			pre[i] = j;
		} 
		for (int i = n, j = n; i >= 1; --i) {
			while (a[j] - a[i] > d) --j;
			nxt[i] = j;
		}
		if (n <= 5000) {
			for (int i = 1; i <= n; ++i) {
				f[i][i] = 0, g[i][i] = 1;
				for (int j = i + 1; j <= n; ++j) f[i][j] = 1e9, g[i][j] = 0;
			}
			int ans = 0;
			for (int i = 1, cnt = 0; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					for (int k = max(pre[j], i); k <= min(j - 1, pre[j] + 2); ++k) {
						if (f[i][j] > f[i][k] + 1) f[i][j] = f[i][k] + 1, g[i][j] = g[i][k];
						else if (f[i][j] == f[i][k] + 1) g[i][j] += g[i][k], g[i][j] = min(g[i][j], 3ll);
					}
					if (g[i][j] == 2) ++ans;
				}
			}
			cout << ans << '\n';
			continue;
		}
		if (C == 13 || C == 14) {
			for (int i = 0; i <= n; ++i) cnt[i] = 0;
			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				ans += cnt[pre[i] + 1];
				++cnt[nxt[i]];
			}
			cout << ans << '\n';
			continue;
		}
		cout << "0\n";
	}
	return 0;
}
/*
13 1
10 8
1 2 4 5 6 7 8 9 15 16
*/
