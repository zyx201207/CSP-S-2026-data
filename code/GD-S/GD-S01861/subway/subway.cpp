#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int x,y,n,m,q,k,w[500005],f[505][505],dis[505][505],ans;
vector<pair<int,int>>v[500005],g[505];
priority_queue<pair<int,int>>p;
bool vis[505];
void dijk(int st){
	memset(vis,0,sizeof(vis));
	dis[st][st]=0;
	p.push({0,st});
	while(p.size()){
		int u=p.top().second;
		p.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:g[u]){
			int v=e.first,w=e.second;
			if(dis[st][u]+w<dis[st][v]) dis[st][v]=dis[st][u]+w,p.push({-dis[st][v],v});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	memset(dis,0x3f,sizeof(dis));
	memset(f,0x3f,sizeof(f));
	cin>>x>>n>>m>>y>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--) cin>>x>>y,v[x].push_back({i,y});
	}
	for(int i=1;i<=m;i++)
		for(auto e1:v[i])
			for(auto e2:v[i])
				if(e1!=e2) f[e1.fi][e2.fi]=min(f[e1.fi][e2.fi],e1.se+e2.se);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]!=0x3f3f3f3f3f3f3f3f)
				g[i].push_back({j,f[i][j]}),g[j].push_back({i,f[i][j]});
	for(int i=1;i<=n;i++) dijk(i);
	while(q--){
		ans=0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		for(auto e1:v[x])
			for(auto e2:v[y]) ans=min(ans,e1.se+e2.se+dis[e1.fi][e2.fi]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

