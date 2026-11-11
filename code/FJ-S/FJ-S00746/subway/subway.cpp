#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=505,M=5e5+5;
const ll INF=1e18;

struct Edge{
	int v;
	ll t;
};

int n,m,d,q;
ll dis[N][N],w[M];
vector<Edge> edge[M];
bool vis[N];

void Dij(int s){
	for(int i=1;i<=n;i++)vis[i]=false;
	for(int rd=s;rd<=n;rd++){
		int p=-1;
		ll mn=INF;
		for(int i=s;i<=n;i++){
			if(vis[i])continue;
			if(dis[s][i]<mn){
				mn=dis[s][i];
				p=i;
			}
		}
		for(int i=s;i<=n;i++)dis[s][i]=min(dis[s][i],dis[s][p]+dis[p][i]);
		vis[p]=true;
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			ll t;
			cin>>a>>t;
			edge[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=(i==j?0:INF);
	for(int i=1;i<=m;i++){
		d=int(edge[i].size());
		for(int j=0;j<d;j++)
			for(int k=j+1;k<d;k++){
				int u=edge[i][j].v,v=edge[i][k].v;
				if(u>v)swap(u,v);
				ll t=edge[i][j].t+edge[i][k].t;
				dis[u][v]=min(dis[u][v],t);
			}
	}
	for(int i=1;i<=n;i++)Dij(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		for(Edge i:edge[x])
			for(Edge j:edge[y])
				ans=min(ans,dis[min(i.v,j.v)][max(i.v,j.v)]+i.t+j.t+w[x]+w[y]);
		cout<<ans<<'\n';
	}
	return 0;
}
