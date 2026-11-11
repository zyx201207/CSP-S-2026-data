#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7,INF=0x3f3f3f3f;
ll c,n,m,s,d,q,x,y,t,a,w[maxn],dist[maxn];
bool vis[maxn];
struct node{
	ll v,w;
};
vector<node>g[maxn];
void dij(ll s){
	memset(dist,INF,sizeof(dist));
	memset(vis,false,sizeof(vis));
	priority_queue<pair<ll,ll> >q;
	dist[s]=0;
	q.push({0,s});
	while(!q.empty()){
		ll u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=true;
		for(auto z:g[u]){
			ll v=z.v,w=z.w;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	s=m;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>c;
		for(ll j=1;j<=c;j++){
			cin>>a>>t;
			g[++s].push_back({a,t});
			g[a].push_back({s,t});
			g[s].push_back({s-1,0});
			g[s-1].push_back({s,0});
		}
	}
	while(q--){
		cin>>x>>y;
		dij(x);
		cout<<w[x]+w[y]+dist[y]<<endl;
	}
	return 0;
}
