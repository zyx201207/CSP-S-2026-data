#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l;i <= (r);i ++)
#define per(i,l,r) for(int i = l;i >= (r);i --)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const int N=5e2+5,M=5e5+5,INF=1e18;
int c,n,m,d,q,k[N],A[M],h[M],D[N],dis[N][N];
vector<pii>a[M];
void Solve() {
	cin >> c >> n >> m >> d >> q;
	rep(i,1,m) cin >> A[i];
	rep(i,1,n) {
		cin >> k[i];
		rep(j,0,k[i]-1) {
			int v,w;
			cin >> v >> w;
			a[v].pb({i,w}),D[v]++;
		}
	}
	memset(dis,0x3f,sizeof dis);
	rep(i,1,m) rep(j,0,D[i]-1) rep(k,j+1,D[i]-1) {
		int u=a[i][j].fi,v=a[i][k].fi,w=a[i][j].se+a[i][k].se;
		dis[u][v]=min(dis[u][v],w);
	}
	rep(i,1,n) rep(j,1,n) dis[i][j]=min(dis[i][j],dis[j][i]);
	rep(i,1,n) dis[i][i]=0;
	rep(k,1,n) rep(i,1,n) rep(j,1,n) 
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	rep(i,1,q) {
		int u,v,ans=INF; cin >> u >> v;
		rep(i,0,D[u]-1) rep(j,0,D[v]-1) {
			int U=a[u][i].fi,V=a[v][j].fi,W=a[u][i].se+a[v][j].se;
			ans=min(ans,W+dis[U][V]);
		} 
		cout << ans+A[u]+A[v] << "\n";
	}
	return ;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int dc=0,T=1,id;
	if(dc) cin >> T;
	rep(i,1,T) Solve();
	return 0;
}

