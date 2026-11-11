#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=505,inf=1e18;
int type,n,m,d,q,dis[M][M],w[N];
struct node{
	int v,w;
};
vector<node>g[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>type>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin >>w[i];
	for(int i=1,k,u,v;i<=n;i++){
		cin >>k;
		while(k--){
			cin >>u>>v;
			g[u].push_back({i,v});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=inf;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)for(int j=0;j<g[i].size();j++)for(int k=0;k<j;k++){
		int u1=g[i][j].v,u2=g[i][k].v,w1=g[i][j].w,w2=g[i][k].w;
		dis[u1][u2]=dis[u2][u1]=min(dis[u1][u2],w1+w2);
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	while(q--){
		int x,y,ans=inf;
		cin >>x>>y;
		for(int i=0;i<g[x].size();i++)for(int j=0;j<g[y].size();j++){
			int u1=g[x][i].v,w1=g[x][i].w,u2=g[y][j].v,w2=g[y][j].w;
			ans=min(ans,w1+w2+dis[u1][u2]);
		}
		cout <<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

