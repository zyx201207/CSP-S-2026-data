#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int f,n,m,e,q,a[1000010],b[N][N],c[N],d[N],g[1000010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>f>>n>>m>>e>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=1e8;
		}
	}
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>g[i];
		for(int j=1;j<=g[i];j++)cin>>c[j]>>d[j];
		for(int j=1;j<=g[i];j++){
			for(int k=j+1;k<=g[i];k++){
				b[c[j]][c[k]]=min(b[c[j]][c[k]],d[j]+d[k]);
				b[c[k]][c[j]]=b[c[j]][c[k]];
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(b[x][y]==1e8){
			for(int i=1;i<=m;i++)b[x][y]=min(b[x][y],b[x][i]+b[i][y]);
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					b[x][y]=min(b[x][y],b[x][i]+b[i][j]+b[j][y]);
				}
			}
		}
		cout<<b[x][y]+a[x]+a[y]<<endl;
	}
	return 0;
}

