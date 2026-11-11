#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
#define N 2000005
#define HMY return
#define pb push_back
#define pii pair<int,int>
int dist[N],c,n,m,d,q,w[N],cnt[N];
vector<pii>adj[N];
void Dijkstra(int s){
	memset(dist,0x3f3f3f,sizeof(dist));
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	int vis[N];
	memset(vis,0,sizeof(vis));
	pq.push({s,0});
	dist[s]=0;
	while(!pq.empty()){
		auto [u,k]=pq.top();
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i].first,w=adj[u][i].second;
			if(k+w<dist[v]){
				dist[v]=w+k;
				cnt[v]=0;
				pq.push({v,dist[v]});
			}
			if(dist[v]==k+w){
				cnt[v]++;
			}
		}
	}
}
void solve(){
	int n,d;
	cin>>n>>d;
	int x[N],ans=0;
	for(int i=1;i<=n;i++) cin>>x[i],adj[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&abs(x[j]-x[i])<=d){
				adj[i].pb({j,1});
				adj[j].pb({i,1});
			}
		}
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		Dijkstra(i);
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			if(cnt[j]==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	FILE("migrate")
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	HMY 0;
}
