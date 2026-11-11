#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N=505, M=5e5+5, Q=1e5+5;
const ll inf = 4e12;
int c, n, m, d, q, w[M];
ll f[N][N];
vector<pii> edg[M];//每个站的线路和距离 

inline void chkmn(ll &x, ll y){
	x = x>y?y:x;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i=1; i<=m; ++i) scanf("%d", w+i);
	for(int i=1,k,u,t; i<=n; ++i){
		scanf("%d", &k);
		for(int j=1; j<=k; ++j){
			scanf("%d%d", &u, &t);
			edg[u].emplace_back(make_pair(i, t));//记录每个站连的线 
		}
	}

	for(int i=1; i<=n; ++i)//Floyd求出两条线换乘的最短路 
		for(int j=1; j<=n; ++j){
			if(i != j) f[i][j] = inf;
		}
	for(int i=1; i<=m; ++i)
		for(int j=0; j<edg[i].size()-1; ++j)
			for(int k=j+1,u,v; k<edg[i].size(); ++k){
				u=edg[i][j].fi, v=edg[i][k].fi;
				ll tf = edg[i][j].se+edg[i][k].se;
//				printf("%d %d %lld\n", u, v, tf);
				chkmn(f[u][v], tf);
				chkmn(f[v][u], tf);
			}
	for(int k=1; k<=n; ++k)
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				chkmn(f[i][j], f[i][k]+f[k][j]);

//	printf("%lld %lld\n%lld %lld\n", f[1][1], f[1][2], f[2][1], f[2][2]);
	ll ans;
	for(int i=1,u,v; i<=q; ++i){
		scanf("%d%d", &u, &v);
		ans = inf;
		for(pii j:edg[u])//枚举最初和最后乘的线路 
			for(pii k:edg[v]){
				chkmn(ans, f[j.fi][k.fi]+j.se+k.se);
			}
		ans += w[u]+w[v];
		printf("%lld\n", ans);
	}
	return 0;
}
