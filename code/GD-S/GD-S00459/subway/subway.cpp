#include <bits/stdc++.h>
#define LL long long
using namespace std ;
const int N=5e5+10 ;
LL c,n,ddd,Q,m ;
LL w[N] ;
vector <pair <LL,LL> > zt[N],G[N] ;
LL k[N] ;
LL d[505][505],vis[505],dd[505][505] ;
priority_queue <pair <LL,LL> > q ;
void dij (LL s) {
	for (LL i=1;i<=n;i++) vis[i]=0,d[s][i]=1e18 ;
	d[s][s]=0 ;
	q.push ({0,s}) ;
	while (q.size ()) {
		LL u=q.top ().second ; q.pop () ;
		if (vis[u]) continue ;
		vis[u]=1 ;
		for (pair <LL,LL> vi:G[u]) {
			LL v=vi.first,w=vi.second ;
			if (d[s][v]>d[s][u]+w) {
				d[s][v]=d[s][u]+w ;
				q.push ({-d[s][v],v}) ;
			}
		}
	}
}
int main () {
//	system ("fc hh subway4.ans") ;
	freopen ("subway.in","r",stdin) ;
	freopen ("subway.out","w",stdout) ;
//	freopen ("subway4.in","r",stdin) ;
//	freopen ("hh","w",stdout) ;
	cin>>c>>n>>m>>ddd>>Q ;	
	for (LL i=1;i<=m;i++) {
		cin>>w[i] ;
	} 
	for (LL i=1;i<=n;i++) {
		cin>>k[i] ;
		for (LL j=1;j<=k[i];j++) {
			LL x,t ;
			cin>>x>>t ;
			zt[x].push_back ({i,t}) ;
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (i!=j) dd[i][j]=1e18 ;
		}
	}
	for (LL i=1;i<=m;i++) {
		for (pair <LL,LL> vi:zt[i]) {
			LL v=vi.first,w=vi.second ;
			for (pair <LL,LL> iv:zt[i]) {
				LL vv=iv.first,ww=iv.second ;
				if (vv==v) break ;
				dd[v][vv]=dd[vv][v]=min (dd[vv][v],w+ww) ;
			}
		}
	}
	if (c<=22) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<i;j++) {
				if (dd[i][j]!=1e18) 
				G[i].push_back ({j,dd[i][j]}),
				G[j].push_back ({i,dd[i][j]}) ;
			}
		}
		for (LL i=1;i<=n;i++) {
			dij (i) ;
		}
	}
	else {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) d[i][j]=dd[i][j] ;
		}
		for (int k=1;k<=n;k++) {
			for (int i=1;i<=n;i++) {
				for (int j=1;j<=n;j++) {
					d[i][j]=min (d[i][j],d[i][k]+d[k][j]) ;
				}
			}
		}
	}
	while (Q--) {
		LL x,y ;
		LL ans=1e18 ;
		cin>>x>>y ;
		for (pair <LL,LL> vi:zt[x]) {
			LL v=vi.first,www=vi.second ;
			for (pair <LL,LL> iv:zt[y]) {
				LL vv=iv.first,ww=iv.second ;
				ans=min (ans,w[x]+www+w[y]+ww+d[v][vv]) ;
			}
		}
		cout<<ans<<'\n' ;
	}
	return 0 ;
} 
