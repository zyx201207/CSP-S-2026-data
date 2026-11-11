#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1E5+7,INF=1E17;
	ll n,m,c,d,q,w[N],dis[N],len,t[N];
	vector<pair<ll,ll>> edg[N];
	bool vis[N];
struct nod{
	ll u,k;
	bool operator<(const nod&r) const{
		return k>r.k;
	}
};
void dijk(ll st){
	priority_queue<nod> q;
	for(ll i=1;i<=len;i++){
		dis[i]=INF;
		vis[i]=false;
	}
	q.push({st,0});
	dis[st]=0;
	while(!q.empty()){
		nod p=q.top();
		q.pop();
		ll u=p.u;
		if(vis[u]) continue;
		vis[u]=true;
		for(auto h:edg[u]){
			ll v=h.first;
			if(dis[u]+h.second<dis[v]){
				dis[v]=dis[u]+h.second;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
		cin>>c>>n>>m>>d>>q;
		for(ll i=1;i<=m;i++) cin>>t[i];
		for(ll i=1;i<=n;i++){
			ll a,t,k;
			cin>>k;
			for(ll j=1;j<=k;j++){
				cin>>a>>t;
				edg[i+m].push_back({a,t});
				edg[a].push_back({i+m,t});
			}
		}
		len=n+m;
	while(q--){
			ll x,y;
			cin>>x>>y;
		dijk(x);
		cout<<t[x]+t[y]+dis[y]<<endl;
	}
	return 0;
}
