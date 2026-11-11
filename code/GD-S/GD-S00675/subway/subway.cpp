#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int v,w;
};
vector<edge> adj[500007],a[507];
int c,n,m,d,q,w[500007],dist[507][507],k,u,v,t;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>t;
			adj[v].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<adj[i].size();j++){
			for(int k=j+1;k<adj[i].size();k++){
				a[adj[i][j].v].push_back({adj[i][k].v,adj[i][k].w+adj[i][j].w});
				a[adj[i][k].v].push_back({adj[i][j].v,adj[i][k].w+adj[i][j].w});
			}
		}
	}
	memset(dist,0x3f3f,sizeof(dist));
	for(int i=1;i<=n;i++){
		dist[i][i]=0;
		for(auto v:a[i]){
			dist[i][v.v]=min(dist[i][v.v],v.w);
			dist[v.v][i]=min(dist[v.v][i],v.w);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]); 
			} 
		}
	}
	while(q--){
		cin>>u>>v;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(auto x:adj[u]){
			for(auto y:adj[v]){
				ans=min(ans,dist[x.v][y.v]+x.w+y.w); 
			}
		}
		cout<<w[u]+w[v]+ans<<"\n";
	} 
	return 0;
}

