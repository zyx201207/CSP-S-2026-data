#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=500010;
const ll inf=1e18;
int _,n,m,d,q;
ll w[M];
struct node{
	int x;
	ll w;
};
vector<node>g[M];
ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int x;
			ll w;
			cin>>x>>w;
			g[x].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=inf;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)for(int j=0;j<(int)g[i].size();j++)for(int k=j+1;k<(int)g[i].size();k++){
		int x=g[i][j].x,y=g[i][k].x;
		ll w=g[i][j].w+g[i][k].w;
		dis[x][y]=min(dis[x][y],w),dis[y][x]=min(dis[y][x],w);
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(int i=0;i<(int)g[x].size();i++)for(int j=0;j<(int)g[y].size();j++){
			int u=g[x][i].x,v=g[y][j].x;
			ll w=dis[u][v]+g[x][i].w+g[y][j].w;
			ans=min(ans,w);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
    return 0;
}

