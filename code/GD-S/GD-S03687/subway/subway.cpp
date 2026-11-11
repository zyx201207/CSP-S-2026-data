#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
const ll M = 2e3;
const ll K = 2e3;
vector<pair<ll,ll> > g[N];
ll c,n,m,d,q;
ll w[N];
ll t[M][K];
ll r;
ll dist[N];
ll k[N];
ll x,y;
struct node{
	ll first;
	ll second;
	bool operator<(const node& other)const{
		return second > other.second;
	}
};
priority_queue<node> pq;
void bfs(){
	while(pq.empty()!=1){
		pq.pop();
	}
	pq.push({x,0});
	while(pq.empty()!=1){
		node u = pq.top();
		pq.pop();
		if(dist[u.first] < (u.second)){
			continue;
		}
		for(pair<ll,ll> to : g[u.first]){
			ll v = to.first;
			ll w = to.second;
			if(dist[u.first]+w < dist[v]){
				dist[v] = dist[u.first]+w;
				node r = {v,dist[v]};
				pq.push(r);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		ll u,t;
		cin>>u>>t;
		g[i*m+u].push_back({u,t});
		g[u].push_back({i*m+u,t});
		for(int j=2;j<=k[i];j++){
			ll v;
			cin>>v>>t;
			g[i*m+u].push_back({i*m+v,0});
			g[i*m+v].push_back({i*m+u,0});
			g[i*m+v].push_back({v,t});
			g[v].push_back({i*m+v,t});
			u = v;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		memset(dist,0x3f,sizeof(dist));
		dist[x]=0;
		bfs();
		cout<<w[x]+w[y]+dist[y]<<endl;
	}
	return 0;
}
