#include <bits/stdc++.h>
#define scan(x) scanf("%lld", &x)
#define scan2(x, y) scanf("%lld%lld", &x, &y)
#define scan3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
using namespace std;
using ll = long long;
using LL = long long;
#define filename "subway"
constexpr LL N = 1000100;

LL n, m, d, q, w[N], k[N], t[510][510], res;
vector <LL> g[N];

void dfs(LL u, LL tg, LL fa, LL sum) {
	if(u == tg) { res = max(res, sum); return ; }
	for(LL v : g[u]) if(v != fa) dfs(v, tg, u, sum + t[u][u] + w[v]);
}

void solve() {
	LL c; scan3(c, n, m), scan2(d, q);
	for(LL i = 1; i <= m; i ++) scan(w[i]);
	for(LL i = 1; i <= n; i ++) {
		scan(k[i]);
		for(LL j = 1, v; j <= k[i]; j ++) scan2(v, t[i][j]), g[i].push_back(v);
	}
	LL r; scan(r);
	while(r --) {
		res = 0;
		LL x, y; scan2(x, y);
		dfs(x, y, 0, 0);
		printf("%lld\n", res);
	}
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
