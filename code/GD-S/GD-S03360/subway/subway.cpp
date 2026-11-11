#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],dis[505][505];
vector<pair<int,int>>p[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			p[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<p[i].size();j++)
			for(int k=j+1;k<p[i].size();k++){
				int u=p[i][j].first,v=p[i][k].first,d=p[i][j].second+p[i][k].second;
				dis[u][v]=min(dis[u][v],d);
				dis[v][u]=min(dis[v][u],d); 
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u,v,ans=1e18;cin>>u>>v;
		for(auto p1:p[u])
			for(auto p2:p[v])
				ans=min(ans,w[u]+w[v]+p1.second+p2.second+dis[p1.first][p2.first]);
		cout<<ans<<'\n';
	}
	return 0;
}

