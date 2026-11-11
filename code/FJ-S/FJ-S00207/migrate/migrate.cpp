#include <bits/stdc++.h>
#define Write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define Na1L0n9 cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int N = 5e3 + 10;
const int MOD = 998244353;
const ll INF = 1e18;
using namespace std;
ll c, t, n, d, mn, x[N], r[N]; // f 表示当前最短数量 g 表示当前最短长度 
void dfs(ll s, ll p, ll t, ll &cnt, ll stp) {
	if (stp > mn) return;
	if (cnt > 2) return;
	if (p == t) {
		if (!cnt) mn = stp;
//		if (s == 2 && t == 5) cout << mn << "vvf\n";
		//if ((stp == (ll)ceil((t - s) * 1.0 / d))) cout << s << " " << t << " " << stp << "\n";
		cnt += (stp == mn);
		return;
	}
	
	for (int i = min(t, r[p]); i > p; i--) dfs(s, i, t, cnt, stp + 1);
}
int main() {
	Write by Na1L0n9
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++) r[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
//		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = 0;
//		for (int i = 1; i <= n; i++) f[i][0] = 1;
//		for (int i = 1; i <= n; i++) {
//			for (int j = i - 1; j && x[i] - x[j] <= d; j--) {
////				if (g[i] > g[j] + 1) g[i] = g[j] + 1, f[i] = 1;
////				else if (g[i] == g[j] + 1) f[i] += f[j];
//				f[i] += 
//			}
//		}
//		for (int i = 1; i <= n; i++) cout << f[i] << "\n";
//		ll ans = 0;
//		for (int i = 1; i <= n; i++) for (int j = i - 1; j && x[i] - x[j] <= d; j--) for (int k = (ll)ceil((j - i) / d); k < n; k++) f[i][k] += f[j][k - 1];
		ll ans = 0;
		for (int i = 1; i <= n; i++) for (int j = i + 3; j <= n; j++) {
			if (x[j - 1] + d < x[j]) continue;
			ll cnt = 0; mn = 1e18;
			dfs(i, i, j, cnt, 0);
			ans += (cnt == 2);
//			if (cnt == 2) cout << i << " " << j << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}
//本人挑战本题O(n^2)，失败了，T2想到正解无力回天,AFO了，goodbye 
