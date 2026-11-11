#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct NODE{
	int pos;ll dis;
	bool operator>(const NODE& other) const{
		return dis>other.dis;
	}
};

struct EDGE{
	int to;ll w;
};

ll ztw[500010];
ll dis[600010];
vector<EDGE> edge[600010];
int c,n,m,d,q;
bool vis[600010];

void add(int u,int v,ll val){
	edge[u].push_back({v,val});
}

void dijkstra(int s,int t){
	for(int i=1;i<=m+n;++i){
		dis[i] = 1e18;
		vis[i] = 0;
	}
	priority_queue<NODE,vector<NODE>,greater<NODE> > q;
	dis[s] = 0;
	q.push({s,0});
	while(!q.empty()){
		int u = q.top().pos;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(EDGE i:edge[u]){
			int v = i.to;
			if(dis[u]+i.w<dis[v]){
				dis[v] = dis[u]+i.w;
				q.push({v,dis[v]});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>ztw[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		for(int j=1;j<=k;++j){
			int a;ll t;cin>>a>>t;
			add(m+i,a,t);
			add(a,m+i,t);
		}
	}
	
	for(int i=1;i<=q;++i){
		int x,y;cin>>x>>y;
		dijkstra(x,y);
		ll ans = dis[y]+ztw[x]+ztw[y];
		cout<<ans<<"\n";
	}



	return 0;
}

