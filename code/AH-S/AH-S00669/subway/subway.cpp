#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e6+10,M=5e5+10;
ll vis[N],dis[N];
vector<pair<ll,ll>>g[N];
void dij(ll S){
	priority_queue<pair<ll,ll>>pq;
	pq.push({0,S});
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[S]=0;
	while(!pq.empty()){
		ll arr=pq.top().second;
		pq.pop();
		if (vis[arr])	continue;
		vis[arr]=1;
		for(auto i:g[arr]){
			ll v=i.first,w=i.second;
			if (dis[arr]+w<dis[v]){
				dis[v]=dis[arr]+w;
				pq.push({-dis[v],v});
			}
		}
	}
}

ll c,n,m,d,q;
ll W[M];
ll k[510];
ll ans[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	ll ma=n*m;
	for(ll i=1;i<=m;i++)
		cin>>W[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		ll last=-1;
		for(ll j=1;j<=k[i];j++){
			ll ca,ct;
			cin>>ca>>ct;
			if (last!=-1){
				g[(i-1)*m+last].push_back({(i-1)*m+ca,0});
				g[(i-1)*m+ca].push_back({(i-1)*m+last,0});
			}
			g[(i-1)*m+ca].push_back({ma+ca,ct});
			g[ma+ca].push_back({(i-1)*m+ca,ct});
			last=ca;
		}
	}
	for(ll i=1;i<=m;i++){
		dij(ma+i);
		for(ll j=1;j<=m;j++)
			ans[i][j]=dis[ma+j];
	}
	while(q--){
		ll b,e;
		cin>>b>>e;
		cout<<ans[b][e]+W[b]+W[e]<<'\n';
	}
	return 0;
}
