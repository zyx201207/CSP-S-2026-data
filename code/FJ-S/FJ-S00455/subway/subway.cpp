#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[5005],a[505][5005],t[505][5005],k[505],x,y,f[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k[i];j++){
			for (int l=1;l<=k[i];l++){
				f[a[i][j]][a[i][l]]=f[a[i][l]][a[i][i]]=t[i][j]+t[i][l];
			}
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++){
			for (int l=1;l<=m;l++){
				f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
			}
		}
	}
	for (int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
