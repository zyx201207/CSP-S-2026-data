#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int c, T, n, k, dis[N][N], fa[N], rk[N], ans;
bool G[N][N];
int Find(int root) {
	if(fa[root]==root) return root;
	return fa[root] = Find(fa[root]);
}
void merge(int x, int y) {
	int r = Find(x), s = Find(y);
	if(r==s) return ;
	if(rk[r]>rk[s]) fa[s] = r;
	else if(rk[r]<rk[s]) fa[r] = s;
	else fa[r] = s, rk[s]++;
}
void solve() {
	scanf("%d %d", &n, &k), ans = 1e9;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			dis[i][j] = (i!=j?1e9:0), G[i][j] = 0;
	for(int i=1, u, v; i<n; i++)
		scanf("%d %d", &u, &v),
		dis[u][v] = dis[v][u] = G[u][v] = G[v][u] = 1;
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	for(int mask=0; mask<(1<<n); mask++) {
		for(int i=1; i<=n; i++)
			fa[i] = i, rk[i] = 1;
		int cnt = 0, tot = 0, d = 1e9, now = 0;
		for(int i=0; i<n; i++)
			if(mask>>i&1) cnt++;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(i!=j&&(mask>>i&1)&&(mask>>j&1)&&G[i+1][j+1]) merge(i+1, j+1);
		for(int i=1; i<=n; i++)
			if(Find(i)==i&&(mask>>(i-1)&1)) tot++;
		if(cnt!=k||tot>2) continue;
		for(int i=0; i<n; i++) {
			d = 1e9;
			if(mask>>i&1) d = 0;
			else for(int j=0; j<n; j++)
				if(i!=j&&(mask>>j&1))
					d = min(d, dis[i+1][j+1]);
			now = max(now, d);
		} ans = min(ans, now);
	} printf("%d\n", ans);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d %d", &c, &T);
	while(T--) solve();
	return 0;
}
