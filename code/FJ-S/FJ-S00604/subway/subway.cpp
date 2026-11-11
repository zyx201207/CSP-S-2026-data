#include<bits/stdc++.h>
#define ll long long
#define FOR(x,y,z) for(int x=y;x<=z;x++)
#define ROF(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
const ll N=5e5+5,INF=1e9+7;

struct edge{
	ll v,w;
};
struct node{
	ll dis,u;
	bool operator>(const node& a) const {
		return dis>a.dis;
	}
};
ll dis[N],vis[N];
vector<edge>e[N];
priority_queue<node, vector<node>, greater<node>> q;
void dijkstra(ll n,ll s){
	memset(dis,INF,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		ll u=q.top().u;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto ed : e[u]){
			ll v=ed.v,w=ed.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}

ll c,n,m,d,Q,k,a[N],t[N],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	FOR(i,1,m)cin>>w[i];
	FOR(i,1,n){
		cin>>k;
		FOR(j,1,k)cin>>a[j]>>t[j];
		FOR(x,1,k){
			FOR(y,x+1,k){
				ll w=t[x]+t[y];
				e[a[x]].push_back({a[y],w});
				e[a[y]].push_back({a[x],w});
			}
		}
	}
	while(Q--){
		ll a,b;
		cin>>a>>b;
		dijkstra(m,a);
		cout<<w[a]+w[b]+dis[b];
		if(Q)cout<<"\n";
	}
	return 0;
}

