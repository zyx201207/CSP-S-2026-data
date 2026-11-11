#include<bits/stdc++.h>
using namespace std;
int g[3010][3010];
int w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >>c>>n>>m>>d>>q;
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++){
		int x;
		cin >>x;
		g[i][m+i]=x;
		g[m+i][i]=x;
	} 
	for(int i=1;i<=n;i++){
		int o;
		cin >>o;
		int lx=-1;
		for(int j=1;j<=o;j++){
			int x,y;
			cin>>x>>y;
			if(lx!=-1){
				g[lx][2*m+(i-1)*m+x]=0;
				g[2*m+(i-1)*m+x][lx]=0;
			}
			g[x+m][2*m+(i-1)*m+x]=y;
			g[2*m+(i-1)*m+x][x+m]=y;
			lx=2*m+(i-1)*m+x;
		}
	}
	for(int k=1;k<=(n+2)*m;k++){
		for(int i=1;i<=(n+2)*m;i++){
			for(int j=1;j<=(n+2)*m;j++){
				if(g[i][k]!=0x3f3f3f3f&&g[k][j]!=0x3f3f3f3f)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	} 
	while(q--){
		int x,y;
		cin >>x>>y;
		cout<<g[x][y]<<'\n';
	}
	return 0;
} 
