#include <bits/stdc++.h>
#define scan(x) scanf("%lld", &x)
#define scan2(x, y) scanf("%lld%lld", &x, &y)
#define scan3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
using namespace std;
using ll = long long;
using LL = long long;
#define filename "migrate"
constexpr LL N = 1000100;

LL _c;
LL n, d, a[N << 1], res, rcnt, cnt;

void dfs(LL x, LL sum, LL target) {
	if(x == target) { if(res == sum) rcnt ++; else if(res > sum) rcnt = 0, res = sum; return ; }
	for(LL i = x + 1; i <= n; i ++) if(abs(a[x] - a[i]) <= d) dfs(i, sum + abs(a[x] - a[i]), target);
	else break;
}

void solve() {
	scan2(n, d); cnt = 0;
	for(LL i = 1; i <= n; i ++) scan(a[i]);
	for(LL i = 1; i < n; i ++) for(LL j = i + 1; j <= n; j ++) {
		res = 1e18; rcnt = 0;
		dfs(i, 0, j);
		if(rcnt == 2) cnt ++;
	}
	printf("%lld\n", cnt);
}

int main() {
	freopen(filename  ".in", "r",  stdin);
	freopen(filename ".out", "w", stdout);

	LL t; scan2(_c, t); while(t --)
	solve();

	fclose(stdin );
	fclose(stdout);
	return 0;
}

