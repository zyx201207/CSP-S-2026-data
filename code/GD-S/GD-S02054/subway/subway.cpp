#include <bits/stdc++.h>
using namespace std;
const int maxm=5e5+3;
int c,n,m,d,q,t[maxm];
long long dis[maxm];
vector<pair<int,int> > g[maxm+20];
struct node{
	int u;
	long long d;
	bool operator <(const node &o)const{
		return d>o.d;
	}
};
long long dijkstra(int s,int t){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<node> pq;
	pq.push({s,0});
	dis[s]=0;
	while(!pq.empty()){
		int u=pq.top().u;
		long long d=pq.top().d;pq.pop();
		if(u==t) break;
		if(d>dis[u]) continue;
		for(pair<int,int> p:g[u]){
			int v=p.first,w=p.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({v,dis[v]});
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			g[u+n].push_back({i,w});
			g[i].push_back({u+n,w});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dijkstra(x+n,y+n)+t[x]+t[y]<<"\n";
	}
	return 0;
}
