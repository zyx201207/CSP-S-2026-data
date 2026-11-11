#include <bits/stdc++.h>
#define int long long
#define fin(x) freopen(#x ".in", "r", stdin);
#define fout(x) freopen(#x ".out", "w", stdout);
#define file(x) fin(x);fout(x);
using namespace std;
constexpr int N = 5e5 + 5;
int n, m, a[N], pre[N], ans;
signed main() {
	file(crystal);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
	for (int i = 1, j = 0; i <= n; ++i) {
		while(a[i] * (i - j) - (pre[i] - pre[j]) > m) ++j;
		ans = max(ans, i - j);
	}
	cout << ans;
}
