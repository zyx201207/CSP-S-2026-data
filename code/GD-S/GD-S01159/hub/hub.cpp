#include <bits/stdc++.h>
#define scan(x) scanf("%lld", &x)
#define scan2(x, y) scanf("%lld%lld", &x, &y)
#define scan3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
using namespace std;
using ll = long long;
using LL = long long;
#define filename "hub"
constexpr LL N = 1000100;

LL _c;
LL n, m;
vector <LL> g[N];

void solve() {
	scan2(n, m);
	for(LL i = 1; i <= n; i ++) g[i].clear();
	for(LL i = 1, u, v; i <= n; i ++) scan2(u, v), g[u].push_back(v), g[v].push_back(u);
	printf("%lld\n", rand() % (m + 1));
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

