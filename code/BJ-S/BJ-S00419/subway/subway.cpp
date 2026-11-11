#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,x,w[500005],k[505],y,dis[505][505],ans,t1;
vector<pair<int,int> > v[505],g[500005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			v[i].push_back({x,y});
			g[x].push_back({i,y});
		}
		sort(v[i].begin(),v[i].end());
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				dis[g[i][j].first][g[i][k].first]=min(dis[g[i][j].first][g[i][k].first],g[i][j].second+g[i][k].second);
				dis[g[i][k].first][g[i][j].first]=dis[g[i][j].first][g[i][k].first];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	for(int i=1;i<=q;i++){
		ans=1e18;
		cin>>x>>y;
		for(int j=0;j<g[x].size();j++) for(int k=0;k<g[y].size();k++) ans=min(ans,dis[g[x][j].first][g[y][k].first]+g[x][j].second+g[y][k].second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
