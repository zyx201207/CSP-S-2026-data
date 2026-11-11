#include<bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define drep(i,r,l) for(int i=(r); i>=(l); --i)
using namespace std;
#define pb push_back
#define int long long
const int N=5e5+5,M=505;
int _,n,m,q,w[N],A[M][M];
vector<array<int,2>>E[N]; 
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	FASTIO;
	memset(A,0x3f,sizeof A);
	cin>>_>>n>>m>>_>>q;
	rep(i,1,m) cin>>w[i];
	rep(i,1,n) {
		int k,u,t; cin>>k;
		while(k--) cin>>u>>t,E[m+i].pb({u,t}),E[u].pb({m+i,t});
	}
	rep(i,1,n) for(auto x:E[m+i]) for(auto y:E[x[0]]) A[i][y[0]-m]=min(A[i][y[0]-m],x[1]+y[1]);
	rep(i,1,n) {
		A[i][i]=0;
		rep(j,1,n) A[i][j]=min(A[i][j],A[j][i]);
	}
	rep(k,1,n) rep(i,1,n) rep(j,1,n) A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
	while(q--) {
		int u,v,S=1e18; cin>>u>>v;
		for(auto x:E[u]) for(auto y:E[v]) S=min(S,A[x[0]-m][y[0]-m]+x[1]+y[1]);
		cout<<S+w[u]+w[v]<<'\n';
	}
}
