#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e6 + 5;
int c, t, n, d, x[maxn], dfn[maxn], low[maxn], ans = 0, cnt = 0;
vector<int> e[maxn];

void init() {
	for(int i = 1; i <= n; i++) e[i].clear();
	ans = 0;
	cnt = 0;
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
}

void tarjan(int pos, int fa) {
	int cnter = 0;
	dfn[pos] = low[pos] = ++cnt;
	for(auto y : e[pos]) {
		if(!dfn[y]) {
			tarjan(y, pos);
			low[pos] = min(low[pos], low[y]);
		} else if(y != fa) {
			low[pos] = min(low[pos], low[y]);
		}
	}
}

signed main() {
	(void)freopen("migrate.in", "r", stdin);
	(void)freopen("migrate.out", "w", stdout);
	(void)scanf("%lld %lld", &c, &t);
	while(t--) {
		(void)scanf("%lld %lld", &n, &d);
		for(int i = 1; i <= n; i++) (void)scanf("%lld", &x[i]);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
				if(abs(x[i] - x[j]) <= d) {
					e[i].push_back(j);
				}
			}
		}
//		for(int i = 1; i <= n; i++) {
//			cout << i << ": ";
//			for(auto y : e[i]) cout << y << " ";
//			cout << endl;
//		}
		tarjan(1, 0);
		(void)printf("%lld\n", ans);
		init();
	}
	return 0;
}
