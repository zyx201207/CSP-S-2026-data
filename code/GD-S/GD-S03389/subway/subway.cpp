#include<bits/stdc++.h>
using namespace std;
long long w[1001],f[1501][1501],c,n,m,d,q,K,x,y;
void floyd(){
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=i+1;j<=n+m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
				f[j][i]=f[i][j];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m+n;i++)
	for(int j=1;j<=m+n;j++)
	f[i][j]=1e9;
	for(int i=1;i<=m+n;i++)
	f[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>K;
		for(int j=1;j<=K;j++){
			cin>>x>>y;
			f[i][n+x]=f[n+x][i]=y;
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<w[x]+w[y]+f[x+n][y+n]<<endl;
	}
	return 0;
} 
