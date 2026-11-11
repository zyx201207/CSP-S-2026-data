#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
long long wrr[500010];
long long g[510][510], drr[510][510];

struct node{
	int a;
	long long t;
};

vector<node> st[500010];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for(int i=1; i<=m; i++){
		scanf("%lld", &wrr[i]);
	}
	for(int i=1; i<=n; i++){
		int k;
		scanf("%d", &k);
		for(int j=1; j<=k; j++){
			int a;
			long long t;
			scanf("%d %lld", &a, &t);
			st[a].push_back({i, t});
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i != j) drr[i][j] = g[i][j] = 1e18;
		}
	}
	for(int p=1; p<=m; p++){
		for(int i=0; i<st[p].size(); i++){
			node x = st[p][i];
			for(int j=i+1; j<st[p].size(); j++){
				node y = st[p][j];
				g[x.a][y.a] = min(g[x.a][y.a], x.t + y.t);
				drr[x.a][y.a] = drr[y.a][x.a] = g[y.a][x.a] = g[x.a][y.a];
			}
		}
	}
	for(int p=1; p<=n; p++){
		for(int u=1; u<=n; u++){
			for(int v=1; v<=n; v++){
				drr[u][v] = min(drr[u][v], drr[u][p] + drr[p][v]);
				drr[v][u] = drr[u][v];
			}
		}
	}
	while(q--){
		int x, y;
		scanf("%d %d", &x, &y);
		long long ans = 1e18;
		for(int i=0; i<st[x].size(); i++){
			node u = st[x][i];
			for(int j=0; j<st[y].size(); j++){
				node v = st[y][j];
				ans = min(ans, drr[u.a][v.a] + u.t + v.t);
			}
		}
		ans += wrr[x] + wrr[y];
		printf("%lld\n", ans);
	}
	return 0;
}
