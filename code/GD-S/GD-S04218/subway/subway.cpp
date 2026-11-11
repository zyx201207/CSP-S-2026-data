#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+10;
const int N=510;
int c,n,m,d,p;
int w[M];
int k[N];
vector<int>g[M+N],g2[M+N],g3[N];
int dis[N][N];
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dis[i][j]-dis[i][k]>dis[k][j])
					dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>p; 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			x+=n;
			g[i].push_back(x);
			g[x].push_back(i);
			g2[i].push_back(y);
			g2[x].push_back(y);
		}
	}
	memset(dis,125,sizeof(dis));
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i+n].size();j++){
			int x=g[i+n][j];
			for(int k=j+1;k<g[i+n].size();k++){
				int y=g[i+n][k];
				if(dis[x][y]==dis[0][0])g3[x].push_back(y),g3[y].push_back(x);
				dis[x][y]=dis[y][x]=min(dis[x][y],g2[i+n][j]+g2[i+n][k]);
			}
		}
	}
	floyd();
//	cout<<dis[1][2];
	while(p--){
		int x,y;
		cin>>x>>y;
		x+=n,y+=n;
		int minn=LONG_LONG_MAX;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				int u=g[x][i],v=g[y][j];
				if(u==v){
					minn=min(minn,g2[x][i]+g2[y][j]);
				}
				else minn=min(minn,g2[x][i]+g2[y][j]+dis[u][v]);
//				cout<<u<<" "<<v<<" "<<dis[u][v]<<" "<<g2[x][i]+g2[y][j]<<"\n";
			}
		}
		cout<<minn+w[x-n]+w[y-n]<<"\n";
	}
	return 0;
}

