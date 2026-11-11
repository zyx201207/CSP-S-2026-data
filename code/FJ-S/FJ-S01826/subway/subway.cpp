#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
int w[500005];
int ls[500005][2];
int g[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//cout<<c<<n<<m<<d<<q;
	//memset(g,sizeof(g),0x3f);
	for(int i=1;i<=500;i++)for(int j=1;j<=500;j++)g[i][j]=1e9;
	for(int i=1;i<=500;i++)g[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>ls[j][0]>>ls[j][1];
		for(int x=1;x<=k;x++){
			for(int y=x+1;y<=k;y++){
				int u=ls[x][0],v=ls[y][0];
				g[u][v]=g[v][u]=min(g[u][v],ls[x][1]+ls[y][1]);
				//cout<<"g["<<u<<"]["<<v<<"]="<<g[u][v]<<endl;
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				//cout<<"g["<<i<<"]["<<j<<"]="<<g[i][j]<<endl;
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<g[x][y]+w[x]+w[y]<<endl;
		//cout<<"xy"<<" "<<x<<" "<<y<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/