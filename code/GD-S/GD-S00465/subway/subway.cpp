#include <bits/stdc++.h>
#define ll long long
#define IOS cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
const int M=5e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[M];
ll dis[M+505];
bool vis[M+505];
struct Edge {
	int v,w;
};
struct Node {
	ll du;
	int u;
	bool operator > (const Node& o) const {
		return du>o.du;
	}
};
vector<Edge> g[M];
void dijkstra(int s,int e) {
	priority_queue<Node,vector<Node>,greater<Node> > q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({dis[s],s});
	while(q.size()) {
		int u=q.top().u;
		q.pop();
		vis[u]=1;
		for(Edge e : g[u]) {
			int v=e.v,w=e.w;
			if(dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				if(!vis[v]) q.push({dis[v],v});
			}
		}
	}
}
signed main() {
	IOS
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;++i) cin >> w[i];
	for(int i=1;i<=n;++i) {
		int k;
		cin >> k;
		for(int j=1;j<=k;++j) {
			int a,t;
			cin >> a >> t;
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	if(q>2000) {
		dijkstra(1,n);
		while(q--) {
			int x,y;
			cin >> x >> y;
			cout << abs(dis[x]-dis[y])+w[x]+w[y] << '\n';
		}
		return 0;
	}
	while(q--) {
		int x,y;
		cin >> x >> y;
		dijkstra(x,y);
		cout << dis[y]+w[x]+w[y] << '\n';
	}
	return 0;
}
