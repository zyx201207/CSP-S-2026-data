#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const ll N=5e5+7;
ll c,n,m,d,q;
struct nd{
	ll w,v;
	bool operator > (const nd&x)const{
	 return w > x.w;
	}
	nd(ll wi,ll vi){
		w=wi,v=vi;
	}
};
ll w[N],dis[N*50],vis[N*50];
vector<nd> g[N*50];
void sol(ll s,ll t){
	priority_queue<nd,vector<nd>,greater<nd> >q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push(nd(0,s));
	while(!q.empty()){
		ll u=q.top().v;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(ll i=0;i<g[u].size();i++){
			ll v=g[u][i].v,w=g[u][i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					q.push(nd(dis[v],v));
				}
			}
		}
	}
	cout << dis[t] <<"\n";
	return ;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(ll i=1;i<=m;i++){
		cin >> w[i];
		g[i].push_back(nd(w[i],i+m));
		g[i+m].push_back(nd(w[i],i));
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin >> k;
		ll lsa=0;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin >> a >> t;
			g[(i+1)*m+a].push_back(nd(t,m+a));
			g[m+a].push_back(nd(t,(i+1)*m+a));
			if(lsa!=0){
				g[(i+1)*m+a].push_back(nd(0,(i+1)*m+lsa));
				g[(i+1)*m+lsa].push_back(nd(0,(i+1)*m+a));
			}
			lsa=a;
		}
	}
	while(q--){
		ll x,y;
		cin >> x >> y;
		sol(x,y);
	}
	return 0;
}
