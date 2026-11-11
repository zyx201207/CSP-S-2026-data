#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
const ll N=1010;
ll n,k;
ll g[N][N];
ll dis[N][N],mz[N],dist[N];
bool vis[N];
vector<ll> adj[N];
void bfs(ll s){
	queue<ll> q;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		ll u=q.front();
		
		q.pop();
		for(auto v:adj[u]){
			if(!vis[v]){
				q.push(v);
				vis[v]=1;
				dist[v]=dist[u]+1;
				cout<<dist[v];
				mz[v]=min(mz[v],dist[v]);
			}
		}
	}
	//cout<<mz[s]<<"\n";
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c;
	cin>>c;
	ll T;
	cin>>T;
	while(T--){
		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));
		memset(dist,0,sizeof(dist));
		memset(mz,0x3f,sizeof(mz));
		memset(dis,0x3f,sizeof(dis));
		for(ll i=1;i<=n;i++){
			adj[i].clear();
		}
		cin>>n>>k;
		if(k==2){
			for(ll i=1;i<n;i++){
				ll u,v;
				cin>>u>>v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			for(ll i=1;i<=n;i++){
				memset(dist,0,sizeof(dist));
				memset(vis,0,sizeof(vis));
				bfs(i);
				
			}
			ll mi=1e9;
			
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					mi=min(mi,max(mz[i],mz[j]));
				}
			}
			cout<<mi<<"\n";
			
		}
		/*else{
			for(ll i=1;i<n;i++){
				ll u,v;
				cin>>u>>v;
				g[u][v]=g[v][u]=1;
			}
			for(ll k=1;k<=n;k++){
				for(ll i=1;i<=n;i++){
					for(ll j=1;j<=n;j++){
						
					}
				}
			}
		}*/
	}
	
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
