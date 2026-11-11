#include <bits/stdc++.h>
#define int long long
#define rd read()
using namespace std;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}
const int N = 5005;
int n, d, a[N], f[N], g[N], ans;
struct BIT {
	int s[N];
	inline void clr() {memset(s, 0, sizeof s);}
	inline void add(int x, int v) {for (; x <= n; x += x & -x) s[x] += v;}
	inline int ask(int x) {int res = 0; for (; x; x -= x & -x) res += s[x]; return res;}
} T;
inline void solve() {
	n = rd, d = rd; ans = 0;
	for (int i = 1; i <= n; ++i) a[i] = rd;
	sort(a + 1, a + 1 + n);
	for (int l = 1; l <= n; ++l) {
		for (int i = 1; i <= n; ++i) f[i] = 0, g[i] = 1e18;
		g[l] = 0, f[l] = 1;
		T.clr(); T.add(l, 1);
		for (int i = l + 1; i <= n; ++i) {
			int pl = l, pr = i - 1, res = i;
			while (pl <= pr) {
				int mid = pl + pr >> 1;
				if (a[i] - a[mid] <= d) pr = mid - 1, res = mid;
				else pl = mid + 1;
			}
			if (i == res) break ;
			g[i] = g[res] + 1;
			int L = res, R = i - 1, rl = res;
			while (L <= R) {
				int mid = L + R >> 1;
				if (g[mid] == g[res]) L = mid + 1, rl = mid;
				else R = mid - 1;
			}
			f[i] = T.ask(rl) - T.ask(res - 1);
			T.add(i, f[i]);
			if (f[i] == 2) ++ans;
		}
	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	int c = rd, T = rd; while (T--) solve();
	return 0;
}
