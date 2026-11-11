#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define inf -1e18
#define se second
#define fi first
using namespace std;
int c,k[505][505],v[500005],d,q,s,x,y,b[505][505],fx,fy,mi,n,m;
vector<pii>a[500005];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&v[i]);
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++)
			k[i][j]=-inf,k[i][i]=0;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&s);
		for(int j=1;j<=s;j++) {
			scanf("%lld%lld",&x,&y);
			a[x].push_back({y,i});
		}
	}
	for(int i=1;i<=m;i++) {
		for(pii p:a[i]) {
			for(pii pp:a[i]) {
				if(p==pp) continue;
				k[p.se][pp.se]=min(k[p.se][pp.se],p.fi+pp.fi);
			}
		}
	}
	for(int kk=1;kk<=n;kk++) 
		for(int ii=1;ii<=n;ii++)
			for(int jj=1;jj<=n;jj++) 
				if(ii!=kk&&ii!=jj&&jj!=kk&&k[ii][kk]+k[kk][jj]<k[ii][jj])
					k[ii][jj]=k[ii][kk]+k[kk][jj];
	while(q--) {
		scanf("%lld%lld",&fx,&fy);
		mi=-inf;
		for(pii p:a[fx])
			for(pii pp:a[fy]) 
				mi=min(mi,k[p.se][pp.se]+p.fi+pp.fi);
		printf("%lld\n",mi+v[fx]+v[fy]);
	} 
	return 0;
}
