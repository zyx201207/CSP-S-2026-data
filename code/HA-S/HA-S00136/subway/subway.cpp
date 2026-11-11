#include<bits/stdc++.h>
using namespace std;
const int M=500009,N=509;
#define int long long
int n,m,c,d,q,w[M],dis[N][N];
vector<pair<int,int> > g[M];
int k[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			g[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto u:g[i]){
			for(auto v:g[i]){
				if(u.first==v.first) continue;
				dis[u.first][v.first]=min(dis[u.first][v.first],u.second+v.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		int ans=1e18;
		for(auto u:g[x]){
			for(auto v:g[y]){
				ans=min(ans,u.second+v.second+dis[u.first][v.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 
