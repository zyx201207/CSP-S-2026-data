#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505;
const ll INF = 1e18;
int C, n, m, D, Q, w[N], t[N][N];
// t[i][j]：第 i 个线路，点编号为 j 
vector<int> xl[N], p[N];
// 每个点在哪些线路中 每个线路有哪些点 

ll ans;
void dfs(int u, int x, int ed, ll c) {
//	cout<<u<<' '<<x<<' '<<c<<endl;
	if(c > ans) return ;
	if(u == ed) {
		c += t[x][ed];
		ans = min(ans, c);
		return ;
	}
	// 1.从 x 的台走到 u 的厅 
	c += t[x][u];
	for(int y : xl[u]) {
		if(y == x) continue;
		c += t[y][u]; // 2. 从 u 的厅走到 y 的台 
		for(int v : p[y]) {
//			int v = V.first, w = V.second;
			if(v == u) continue;
//			c += t[y][v]; // 3. 从 y 的台走到 v 的厅 
			dfs(v, y, ed, c);
//			c -= t[y][v];
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &C, &n, &m, &D, &Q);
	for(int i=1; i<=m; ++i) {
		scanf("%d", &w[i]);
	}
	ll inff = 0;
	for(int i=1, K, u, w; i<=n; ++i) {
		scanf("%d", &K);
		while(K--) {
			scanf("%d%d", &u, &w);
			inff += w;
			t[i][u] = w;
			xl[u].push_back(i);
			p[i].push_back(u);
		}
	}
//	ll cc;
	for(int i=1, u, v; i<=Q; ++i) {
		scanf("%d%d", &u, &v);
		ans = inff;
		for(int x : xl[u]) {
			for(int st : p[x]) { // 从厅到台 
				dfs(st, x, v, t[x][u]);
			}
		}
		ans += w[u]+w[v];
		printf("%lld\n", ans);
	}
	return 0;
} /*
看不懂题。
暴力怎么做？对于每个 start，dfs 到 end
dfs(u,x,ed)：从 u 的台出发，走线路 x，走到 ed 的台 花费 C 
if(u == ed) return
每次枚举换线路：从 u 的台走到某个线路的台

那就枚举从 u 的哪个 bel 出发，走到 v 的哪个 bel 就行了 


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
