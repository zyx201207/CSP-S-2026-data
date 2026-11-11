#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lpx 500005
#define inf 0x3f3f3f3f3f3f3f3f
ll n,m,dis[lpx],test,t,num,ji=0,qe;
bool vis[lpx];
struct node{
	ll to,cost;
};
struct dian{
	ll to,cost;
	friend bool operator<(dian a,dian b){
		return a.cost>b.cost;
	};
};
vector<node>linker[lpx];
priority_queue<dian>q;
ll dij(ll qi,ll zhong){
	for(ll i=1;i<=ji;++i){dis[i]=inf;vis[i]=false;} 
	dis[qi]=0;
	q.push({qi,dis[qi]});
	while(q.size()){
		ll u=q.top().to;
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(auto v:linker[u]){
			if(dis[v.to]>dis[u]+v.cost){
				dis[v.to]=dis[u]+v.cost;
				q.push({v.to,dis[v.to]});
			}
		}
	}
	return dis[zhong];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>test>>m>>n>>num>>qe;
	ji=n;
	for(ll i=1,a;i<=n;++i){
		cin>>a;
		ji++;
		linker[i].push_back({ji,a});
		linker[ji].push_back({i,a});
	}
	for(ll i=1,k;i<=m;++i){
		cin>>k;
		ji++;
		for(ll j=1,a,b;j<=k;++j){
			cin>>a>>b;
			linker[ji].push_back({n+a,b});
			linker[n+a].push_back({ji,b});
		}
	}
	while(qe--){
		ll x,y;
		cin>>x>>y;
		cout<<dij(x,y)<<"\n";
	}
	return 0;
}
