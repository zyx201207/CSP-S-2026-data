#include <bits/stdc++.h>
#define ll long long
//#define int long long
using namespace std;
const int N=5e5+10+510;
const ll inf=2e18;
int c,n,m,d,q,w[N],k[510];
ll dis[N],pre_dis[N],T;
struct edge{
	int v;
	ll w;
	friend bool operator < (const edge &x,const edge &y){
		return x.w>y.w;
	}
};
vector<edge> g[N];
priority_queue<edge> que;
bool vis[N];
void dijkstra(int s){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m+n;i++)
		dis[i]=inf;
	dis[s]=0;
	que.push({s,dis[s]});
	while(!que.empty()){
		int u=que.top().v;
		que.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(edge e:g[u]){
			int v=e.v;
			ll w=e.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				que.push({v,dis[v]});
			}
		}
	}
}
ll bfsdis[N];
int queb[N],head,tail;
void bfs(int s,int t){
	for(int i=1;i<=n+m;i++)
		bfsdis[i]=inf;
	head=tail=0;
	bfsdis[s]=0;
	queb[tail++]=s;
	while(head<tail){
		int u=queb[head++];
		for(edge e:g[u]){
			int v=e.v;
			if(bfsdis[v]>bfsdis[u]+1){
				bfsdis[v]=bfsdis[u]+1;
				queb[tail++]=v;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int v,w;
			cin>>v>>w;
			T=w;
			g[m+i].push_back({v,w});
			g[v].push_back({m+i,w});
		}
	}
	if(c>=12&&c<=19){
		while(q--){
			int x,y;
			cin>>x>>y;
			bfs(x,y);
			cout<<bfsdis[y]*T+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
} 
