#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,w[405],k[205],a[205][405],t[205][405],x,y,d[405][405];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<=400;i++) for(int j=0;j<=400;j++) d[i][j]=2e18;
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];	
		for(int j=1;j<=k[i];j++) for(int l=1;l<=k[i];l++)
			d[a[i][j]][a[i][l]]=w[a[i][j]]+t[i][j]+w[a[i][l]]+t[i][l];
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) for(int l=1;l<=m;l++)
		d[i][j]=min(d[i][j],d[i][l]+d[l][j]-2*w[l]);
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<d[x][y]<<"\n";
	}return 0;
}
