//GZ-S00166 甘梓辰 贵阳市第一中学
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int c,n,m,d,q,w[500005],k[500005],x,y,dis[505][505];
vector<pii> e[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int t=e[i].size();
		for(int x=0;x<t;x++){
			int u=e[i][x].first,w=e[i][x].second;
			for(int y=x+1;y<t;y++){
				int v=e[i][y].first;
				dis[u][v]=min(dis[u][v],w+e[i][y].second);
				dis[v][u]=min(dis[v][u],w+e[i][y].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		int ans=1e18;
		for(int i=0;i<e[x].size();i++){
			int u=e[x][i].first;
			for(int j=0;j<e[y].size();j++){
				int v=e[y][j].first;
				ans=min(ans,e[x][i].second+e[y][j].second+w[x]+w[y]+dis[u][v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

