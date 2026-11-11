#include <bits/stdc++.h>
using namespace std;
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define pre(i,n) for(int i = n;i;--i)
#define rep(i,n) for(int i = 1;i <= n;++i)
#define rpt(i,a,n) for(int i = a;i <= n;++i)
#define repg(i,u) for(int i = head[u];i;i = e[i].nxt)
#define WR(x) cerr<<#x<<':'<<x<<endl
#define int long long
#define swap(x,y) (x ^= y ^= x ^= y)
typedef pair <int,int> pii;
constexpr int N = 505,M = 5e5 + 5,inf = 1e18;
int dis[N][N],w[M],c,n,m,d,q,k,u,t,v,x,y,res;
vector <pii> vec[M];
signed main(){
	// fin("subway7.in"),fout("subway.out");
	fin("subway.in"),fout("subway.out");
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	rep(i,m) cin>>w[i];
	rep(i,n){
		cin>>k;
		while(k--) cin>>u>>t,vec[u].emplace_back((pii){i,t});
	}
	rep(i,n) rep(j,n) if(i ^ j) dis[i][j] = inf;
	rep(i,m){
		int sz = vec[i].size();
		rpt(j,0,sz - 2) rpt(k,j + 1,sz - 1){
			u = vec[i][j].first,v = vec[i][k].first;
			dis[u][v] = dis[v][u] = min(dis[u][v],vec[i][j].second + vec[i][k].second);
		}
	}
	rep(k,n) rep(i,n) rep(j,n) dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	while(q--){
		cin>>x>>y,res = inf;
		for(auto i : vec[x]){
			u = i.first;
			for(auto j : vec[y]){
				v = j.first;
				res = min(res,dis[u][v] + i.second + j.second);
			}
		}
		cout<<res + w[x] + w[y]<<'\n';
	}
	cerr<<'\n'<<1.0 * clock() / CLOCKS_PER_SEC;
	return 0;
}