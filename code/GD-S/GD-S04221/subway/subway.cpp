#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,long long>
#define pb push_back
const int maxn=505,maxm=5e5+5,maxd=23,maxq=1e5+5;
int c,n,m,d,q;
ll p[maxm];
int k[maxn];
vector<pii>e[maxm];

ll dis[maxn][maxn];
vector<pii>to[maxn];
bool vis[maxn];
priority_queue<pair<ll,int> >qu;
void dijikstra(int x){
	while(qu.size())qu.pop();
	for(int i=1;i<=n;i++)
		dis[x][i]=1e18,vis[i]=0;
	dis[x][x]=0;
	qu.push({-dis[x][x],x});
	while(qu.size()){
		int u=qu.top().second;
		qu.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<to[u].size();i++){
			int v=to[u][i].first;ll w=to[u][i].second;
			if(dis[x][v]>dis[x][u]+w){
				dis[x][v]=dis[x][u]+w;
				qu.push({-dis[x][v],v});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++){
//		cout<<"line: "<<i<<"\n";
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a;
			ll t;
			cin>>a>>t;
//			cout<<a<<" "<<t<<"\n";
			for(int k=0;k<e[a].size();k++){
				int v=e[a][k].first;
				ll w=e[a][k].second;
//				cout<<i<<" "<<w+t<<" "<<v<<"\n";
				to[v].pb({i,w+t});
				to[i].pb({v,w+t});
			}
			e[a].pb({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		dijikstra(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(int i=0;i<e[x].size();i++){
			int xv=e[x][i].first;
			ll xw=e[x][i].second;
			for(int j=0;j<e[y].size();j++){
				int yv=e[y][j].first;
				ll yw=e[y][j].second;
//				cout<<xv<<" "<<dis[xv][yv]+xw+yw+p[x]+p[y]<<" "<<yv<<"\n";
				ans=min(ans,dis[xv][yv]+xw+yw+p[x]+p[y]);
			}
		}
		cout<<ans<<"\n";
	}
}
