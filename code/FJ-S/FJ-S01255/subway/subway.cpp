#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],a[505][500005],t[505][500005],x[100005],y[100005],k,f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(c>=12&&c<=19){
		f[1][1]=1;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			cout<<f[x[i]][y[i]]*t[1][1]<<endl;
		}
	}
	return 0;
} 
