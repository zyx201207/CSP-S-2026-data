#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
const ll INF=1e9;
const int N=1e3+5;
int c,n,m,d,q;
ll w[N];
int tot;
vector<pii> g[N];
bool vis[N];
ll dis[N][N];
void dijkstra(int s){
	for(int i=1;i<=tot;i++){
		vis[i]=0;
		dis[s][i]=INF;
	}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({dis[s][s]=0,s});
	while(!pq.empty()){
		int u=pq.top().se;
		pq.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(pii P:g[u]){
			int v=P.fi;ll w=P.se;
			if(dis[s][v]>dis[s][u]+w){
				pq.push({dis[s][v]=dis[s][u]+w,v});
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	tot=m;
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		int pre=0;
		for(int _=1;_<=len;_++){
			int pos;ll cost;
			cin>>pos>>cost;
			g[pos].push_back({++tot,cost});
			g[tot].push_back({pos,cost});
			if(pre){
				g[pre].push_back({tot,0});
				g[tot].push_back({pre,0});
			}
			pre=tot;
		}
	}
	for(int i=1;i<=m;i++){
		dijkstra(i);
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<w[s]+w[t]+dis[s][t]<<"\n"; 
	}
	return 0;
}

