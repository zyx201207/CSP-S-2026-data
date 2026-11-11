#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10;
const ll INF=0x3f3f3f3f3f3f3f;
vector<pair<ll,ll>> g[N];
ll c,n,m,d,q;
ll tot;
struct nod{
	ll u;
	ll d;
	bool operator<(const nod& o)const{
		return d>o.d;
	}
};
void workk(ll s,ll t){
	priority_queue<nod> qp;
	qp.push({s,0});
	vector<bool> vis(tot+5,0);
	vector<ll> dis(tot+5,INF);
	dis[s]=0;
	while(qp.size()){
		nod x=qp.top();
		qp.pop();
		ll u=x.u;
		if(vis[u]==1)continue;
		vis[u]=0;
		for(auto y:g[u]){
			ll v=y.first;
			ll val=y.second;
			if(v==u)continue;
			if(dis[v]>dis[u]+val){
				dis[v]=dis[u]+val;
				qp.push({v,dis[v]});
			}
		}
	}
	cout<<dis[t]<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		ll w;
		cin>>w;
		g[i].push_back({i+m,w});
		g[i+m].push_back({i,w});
	}
	tot=2*m;
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		ll lst;
		for(ll j=1;j<=k;j++){
			ll u,w;
			cin>>u>>w;
			g[u+m].push_back({++tot,w});
			g[tot].push_back({u+m,w});
			if(j!=1){
				g[lst].push_back({tot,0});
				g[tot].push_back({lst,0});
			}
			lst=tot;
		}
	}
	/*
	for(ll i=1;i<=tot;i++){
		cout<<i<<":";
		for(auto x:g[i]){
			cout<<x.first<<" ";
		}
		cout<<'\n';
	}*/
	while(q--){
		ll s,t;
		cin>>s>>t;
		workk(s,t);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
fc subway.out subway3.ans 
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
