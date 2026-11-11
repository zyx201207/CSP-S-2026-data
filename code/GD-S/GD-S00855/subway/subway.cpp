#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define Rep(i,j,k) for(int i=j;i>=k;--i)
#define L(i,j,k) for(int i=j;i<k;++i)
#define mem(x,v) memset(x,v,sizeof x)
#define Sz(s) (s).size()
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll = long long;
const int N = 505, M = 5e5+10, V = 21;
const ll INF = 1e16;
using vi = vector<int>;
using pii = pair<int,int>;
void ckmin(ll &x,ll y){
	x = min(x, y); return;
}
int c, n, m, d, q, k[N], w[M]; ll vv[N], val[N][N]; vector<pii> G[M]; map<int,ll> dis[M];
void solve(){
	cin >> c >> n >> m >> d >> q;
	rep(i,1,m) cin >> w[i];
	rep(i,1,n){
		cin >> k[i];
		rep(j,1,k[i]){
			int v, w; cin >> v >> w; G[v].pb({i, w});
		}
	}
	rep(i,1,n){
		rep(j,1,n) val[i][j] = INF; 
		val[i][i] = 0;
	}
	rep(k,1,m){
		int V = Sz(G[k]);
		L(i,0,V){
			L(j,i+1,V){
				int x = G[k][i].fi, v1 = G[k][i].se, y = G[k][j].fi, v2 = G[k][j].se;
				ckmin(val[x][y], (ll)(v1 + v2)), ckmin(val[y][x], (ll)(v1 + v2));
			}
		}
	}
	rep(u,1,m){
		for(auto k:G[u]){
			int s = k.fi; ll ww = k.se;
			if(!dis[u].count(s)) dis[u][s] = ww;
			else ckmin(dis[u][s], ww);  
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				ckmin(val[i][j], val[i][k] + val[k][j]);
			}
		}
	}
	rep(u,1,m){
		for(auto k:dis[u]){
			int v = k.first; ll w = k.second; 
			rep(o,1,n){
				ll g = w + val[v][o];
				if(!dis[u].count(o)) dis[u][o] = g;
				else ckmin(dis[u][o], g); 
			}
		}
	}
	while(q--){
		int u, v; ll cost = INF; cin >> u >> v;
		rep(i,1,n) vv[i] = INF;
		for(auto k:G[u]){
			int s = k.fi, ww = k.se; ckmin(vv[s], ww);
		}
		for(auto [x, w] : dis[v]){
			ckmin(cost, vv[x] + w);
		}
		ll res = cost + w[u] + w[v]; 
		cout << res << "\n"; 
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; // cin >> T;
	while(T--){
		solve();
	}
	return 0;
} 
