#include <iostream>
#include <cstdio>
#define ll long long
#define H <<' '<<
using namespace std;
ll C,n,m,D,q,w[500005],g[1005][1005],a[500005],t[500005],ss,tt;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
//	freopen("subway/subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=m;j++){
			g[i][j]=1e15;
		}
		g[i][i]=0;
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(ll i1=1;i1<=k;i1++){
			for(ll i2=1;i2<=k;i2++){
				g[a[i1]][a[i2]]=min(g[a[i1]][a[i2]],t[i1]+t[i2]);
			}
		}
	}
	for(ll k=1;k<=m;k++){
		for(ll i=1;i<=m;i++){
			for(ll j=1;j<=m;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>ss>>tt;
		cout<<g[ss][tt]+w[ss]+w[tt]<<'\n';
	}
	return 0;
}
// 44
