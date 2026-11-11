#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MXM=5e5+5;
int C,n,m,d,q,u,v,k;
ll w,W[MXM],G[505][505];
struct Edge{
	int v;
	ll w;
};
vector<Edge>g[MXM];
int main(){
	// 15:13 100pts
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>W[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>u>>w;
			g[u].push_back({i,w});
		}
	}
	memset(G,0x3f,sizeof(G));
	for(int i=1;i<=n;i++)G[i][i]=0;
	for(int u=1;u<=m;u++){
		for(int i=0;i<g[u].size();i++){
			for(int j=i+1;j<g[u].size();j++){
				const auto &ea=g[u][i],&eb=g[u][j];
				G[ea.v][eb.v]=G[eb.v][ea.v]=min(G[ea.v][eb.v],ea.w+eb.w);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	while(q--){
		cin>>u>>v;
		ll ans=LLONG_MAX/2;
		for(auto &ea:g[u]){
			for(auto &eb:g[v]){
				ans=min(ans,ea.w+eb.w+G[ea.v][eb.v]);
			}
		}
		cout<<ans+W[u]+W[v]<<'\n';
	}
}
