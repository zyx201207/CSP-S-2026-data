#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
const int MAX=1e18+5;
int c,n,m,d,q,w[N],k,t[505][N],dis[505][505];
vector<int>G[N];
void floyd(){
	for(int k=1;k<=n;k++)
		for(int x=1;x<=n;x++)
			for(int y=1;y<=n;y++)
				dis[x][y]=min(dis[x][y],dis[x][k]+dis[k][y]);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			cin>>t[i][a];
			G[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) dis[i][j]=0;
			else dis[i][j]=MAX;
	for(int i=1;i<=m;i++)
		for(int j=0;j<G[i].size();j++)
			for(int k=0;k<G[i].size();k++){
				int u=G[i][j],v=G[i][k];
				dis[u][v]=min(dis[u][v],t[u][i]+t[v][i]);
			}
	floyd();
	while(q--){
		int x,y,ans=MAX;
		cin>>x>>y;
		for(int i=0;i<G[x].size();i++)
			for(int j=0;j<G[y].size();j++){
				int u=G[x][i],v=G[y][j];
				ans=min(ans,dis[u][v]+t[u][x]+t[v][y]);
			}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
