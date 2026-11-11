#include<bits/stdc++.h>
#define int long long
#define N 500005
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int C,Tc=1,n,m,d,q,a[N],dis[505][505];
vector<pii>g[N];
void solve(int cs){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,t;
			cin>>u>>t;
			g[u].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<g[i].size();x++){
			for(int y=x+1;y<g[i].size();y++){
				int u=g[i][x].x,v=g[i][y].x;
				dis[u][v]=dis[v][u]=min(dis[u][v],g[i][x].y+g[i][y].y);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int res=2e18;
		for(auto it:g[x]){
			for(auto itt:g[y]){
				res=min(res,a[x]+a[y]+dis[it.x][itt.x]+it.y+itt.y);
			}
		}
		cout<<res<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C;
//	cin>>Tc;
	for(int cs=1;cs<=Tc;cs++){
		solve(cs);
	}
	return 0;
}
