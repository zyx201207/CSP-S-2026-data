#include <bits/stdc++.h>
#define scan(x) scanf("%lld", &x)
#define scan2(x, y) scanf("%lld%lld", &x, &y)
#define scan3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
using namespace std;
using ll = long long;
using LL = long long;
#define filename "crystal"
constexpr LL N = 5e5 + 10;

LL n, m, a[N], ans, pre1[N], pre2[N];

LL cost(LL x, LL y) { return a[y] * (y - x + 1) - (pre1[y] - pre1[x - 1]) - (pre2[y] - pre2[x - 1]); }

void solve() {
	scan2(n, m);
	for(LL i = 1; i <= n; i ++) scan(a[i]);
	sort(a + 1, a + 1 + n);
	for(LL i = 1; i <= n; i ++) {
		pre1[i] = pre1[i - 1] + max(a[i], 0ll);
		pre2[i] = pre2[i - 1] + min(a[i], 0ll);
		LL l = 1, r = i, res = (i >> 1) + 1;
		while(l < r) {
			LL mid = l + (r - l >> 1);
			if(cost(mid, i) > m) l = mid + 1;
			else r = mid, res = mid;
		}
		if(cost(res, i) > m) continue;
		ans = max(ans, i - res + 1);
	}
	printf("%lld\n", ans);
}

int main() {
	freopen(filename  ".in", "r",  stdin);
	freopen(filename ".out", "w", stdout);
	
//	LL t; scan(t); while(t --)
	solve();
	
	fclose(stdin );
	fclose(stdout);
	return 0;
}
