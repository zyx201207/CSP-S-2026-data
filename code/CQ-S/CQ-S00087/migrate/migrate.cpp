#include<bits/stdc++.h>
#define LL long long
#define PII pair <LL, LL>
using namespace std;
bool bbb;
const LL N = 2e6 + 5;
LL c, n, m, hh, tt, ans;
LL a[N], f[N], g[N], q[N];
void solve() {
	ans = 0;
	cin >> n >> m;
	for(LL i = 1; i <= n; i ++ ) cin >> a[i];
	if(c <= 10) {
		for(LL i = 1; i <= n; i ++ ) {
			for(LL j = 0; j <= n; j ++ ) {
				f[j] = 1e18;
				g[j] = 0;
			}
			f[i] = 0;
			g[i] = 1;
			hh = 0, tt = -1;
			q[ ++ tt] = i;
			for(LL j = i + 1; j <= n; j ++ ) {
				while(hh <= tt && a[q[hh]] + m < a[j]) hh ++ ;
				if(hh > tt) break;
				f[j] = f[q[hh]] + 1;
				g[j] = g[q[hh]];
				if(hh + 1 <= tt && f[q[hh]] == f[q[hh + 1]]) g[j] += g[q[hh + 1]];
				if(hh + 2 <= tt && f[q[hh]] == f[q[hh + 2]]) g[j] += g[q[hh + 2]];
				ans += g[j] == 2;
				while(hh <= tt && f[q[tt]] > f[j]) tt -- ;
				q[ ++ tt] = j;
			}
		}
	} else if(c <= 12) {
		m /= a[2] - a[1];
		if(m <= 1) ans = 0;
		else {
			for(LL i = 1; i <= n; i ++ ) {
				if(i + m + m - 1 <= n) ans ++ ;
			}
		}
	} else if(c <= 14) {
		for(LL i = 1; i <= n; i ++ ) {
			LL p = upper_bound(a + 1, a + n + 1, a[i] + m) - a - 1;
			if(p <= i + 1) continue;
			LL x = upper_bound(a + 1, a + n + 1, a[p - 1] + m) - a - 1;
			LL y = upper_bound(a + 1, a + n + 1, a[p - 2] + m) - a - 1;
			ans += x - y;
		}
	}
	cout << ans << '\n';
}
bool eee;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cerr << abs(&bbb - &eee) / 1024.0 / 1024 << '\n';
	LL t;
	cin >> c >> t;
	while(t -- ) solve();
	return 0;
}


/*


14 3
4 2 
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2



*/
