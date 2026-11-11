#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define M 500005
struct edge{
	int v;
	int w;
};
int c,n,m,d,q;
int w[M];
vector<edge>g[M+1000];
ll dis[M+1000];
bool vis[M+1000];
priority_queue<edge>pq;
bool operator<(edge e1,edge e2){
	return e1.w>e2.w;
}
void dij(int s){
	pq.push({s,0});
	dis[s]=0;
	while(pq.size()){
		int u=pq.top().v;
		pq.pop();
		if(vis[u]) break;
		vis[u]=true;
		for(edge e:g[u]){
			if(dis[u]+e.w<dis[e.v]){
				dis[e.v]=dis[u]+e.w;
				pq.push({e.v,dis[e.v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a,t;
		while(k--){
			cin>>a>>t;
			g[a].push_back({i+m,t});
			g[i+m].push_back({a,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		while(pq.size()) pq.pop();
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
//freopen
//feropen
