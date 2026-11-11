#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500050],f[5010][5010],k,a[500500],t[500500];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j){
			if(i==j)f[i][j]=0;
			else f[i][j]=INT_MAX;
		}
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a[j]>>t[j];
			for(int l=1;l<j;++l)
				f[a[j]][a[l]]=f[a[l]][a[j]]=t[j]+t[l];
		}
	}
	for(int k=1;k<=m;++k)
		for(int i=1;i<=m;++i)
			for(int j=1;j<=m;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}