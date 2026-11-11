#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
#define N 2005
#define HMY return
#define pb push_back
#define pii pair<int,int>
int dist[N],c,n,m,d,q,w[N],a[N][N],t[N][N],pre[N];
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
				pre[v]=u;
				pq.push({v,dist[v]});
			}
		}
	}
//	cout<<"Test\n";
//	cout<<e<<"\n";
//	while(pre[e]){
//		e=pre[e];
//		cout<<e<<'\n';
//	}
//	cout<<"\n";
}
signed main(){
	FILE("subway")
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		//adj[i].pb({500+i,w[i]});
		//adj[500+i].pb({i,w[i]});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			adj[i].pb({500+a[i][j],t[i][j]});
			adj[500+a[i][j]].pb({i,t[i][j]});
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		Dijkstra(500+s);
		cout<<dist[e+500]+w[s+500]+w[e]<<'\n';
	}
	HMY 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
