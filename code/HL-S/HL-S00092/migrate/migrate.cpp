#include <bits/stdc++.h>
#define int long long
#define fin(x) freopen(#x ".in", "r", stdin);
#define fout(x) freopen(#x ".out", "w", stdout);
#define file(x) fin(x);fout(x);
using namespace std;
int c;
namespace Sub1{
	constexpr int N = 5e3 + 5;
	int t, n, m, a[N], f[N], g[N], pre[N], edv[N], ans;
	void solve() {
		cin >> t;
		while(t--) {
			cin >> n >> m, ans = 0;
			for (int i = 1; i <= n; ++i) cin >> a[i];
			for (int p = 1; p <= n; ++p) {
				f[p] = 0, g[p] = 1, pre[p - 1] = 0, pre[p] = 1;
				for (int i = p + 1, j = p; i <= n; ++i) {
					while(a[i] - a[j] > m) ++j;
					if (i == j) break;
					f[i] = f[j] + 1;
					if (f[i] != f[i - 1]) edv[f[i - 1]] = i - 1;
					g[i] = pre[edv[f[j]]] - pre[j - 1], pre[i] = pre[i - 1] + g[i];
					if (g[i] == 2) ++ans;
				}
			}
			cout << ans << '\n';
		}
	}
}
signed main() {
	file(migrate);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> c;
	if (c <= 10) Sub1::solve();	
}

