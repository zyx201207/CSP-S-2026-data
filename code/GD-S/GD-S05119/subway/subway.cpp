#include<bits/stdc++.h>
using namespace std;
long g[500505][500505],w[505],a,ans,n,m,c,d,q,x,y,ki;
void floyd(){
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			for(int k=1;k<=n+m;k++){
				g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
				
			}
		}
	}
}
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			g[i][j]=5e8+5;
		}
		g[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=m+1;i<=n+m;i++){
		cin>>ki;
		for(int j=1;j<=ki;j++){
			cin>>a;
			cin>>g[i][a];
			g[a][i]=g[i][a];
		}
	}
	floyd();
	floyd();
	floyd();
	while(q--){
		cin>>x>>y;
		cout<<g[x][y]+w[x]+w[y]<<endl;
	}
}
