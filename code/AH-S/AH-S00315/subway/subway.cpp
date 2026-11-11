#include <bits/stdc++.h>
#define rep(i,l,r) for(int i = (l);i <= (r);i++)
#define per(i,l,r) for(int i = (r);i >= (l);i--)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)((x).size()))
#define Mod(x) ((x) % P)
#define ModE(x) ((x) %= P)
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using db = double;
constexpr int infI = 1 << 30;
constexpr ll infL = 1ll << 60;

const int M = 5e5 + 10;

const int N = 510;

int c,n,m,d,q;

ll cost[M];

struct Edge{
	int to;
	ll w;
};

vector<Edge> G[N + M];

ll dis[N][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	rep(i,1,n) dis[i][i] = 0;
	rep(i,1,m) scanf("%lld",&cost[i]);
	rep(i,1,n){
		int k;
		scanf("%d",&k);
		rep(j,1,k){
			int u;
			ll w;
			scanf("%d%lld",&u,&w);
			G[m + i].pb({u,w});
			G[u].pb({m + i,w});
		}
	}
	rep(u,1,m){
		rep(i,0,SZ(G[u]) - 1){
			rep(j,i + 1,SZ(G[u]) - 1){
				int x = G[u][i].to - m,y = G[u][j].to - m;
				dis[x][y] = min(dis[x][y],G[u][i].w + G[u][j].w);
				dis[y][x] = min(dis[y][x],G[u][i].w + G[u][j].w);
			}
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	rep(i,1,q){
		int u,v;
		scanf("%d%d",&u,&v);
		ll res = infL;
		rep(i,0,SZ(G[u]) - 1){
			int x = G[u][i].to - m;
			rep(j,0,SZ(G[v]) - 1){
				int y = G[v][j].to - m;
				res = min(res,dis[x][y] + G[u][i].w + G[v][j].w);
			}
		}
		printf("%lld\n",cost[u] + cost[v] + res);
	}
	return 0;
}
