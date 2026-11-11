#include<bits/stdc++.h>
#define ll long long
const int N=5e5+10;
const ll INF=1e14;
using namespace std;
struct node{
	ll id;
	ll num;
	ll tim;
}xian[N][25];
struct qwe{
	ll a;
	ll dist;
	bool operator<(const qwe &aa)const{
		dist>aa.dist;
	}
};
ll c,n,m,d,q,tot[N],dis[N],vis[N];
ll w[N];
vector<pair<ll,ll>> sub[510];
void clear(){
	for(int i=0;i<=m;i++){
		dis[i]=INF;
		vis[i]=0;
	}
}
void di(ll x,ll xd){
	dis[x]=0;
	priority_queue<qwe>q;
	q.push({x,0});
	while(!q.empty()){
		ll u=q.top().a,dist=q.top().dist;
		q.pop();
		if(u==xd)return;
		if(vis[u])continue;
		vis[u]=1;
		if(dist>dis[u]){
			continue;
		}
		for(int i=1;i<=tot[u];i++){
			ll id=xian[u][i].id,num=xian[u][i].num;
			ll tim=xian[u][i].tim;
			for(int j=num;j<int(sub[id].size());j++){
				ll v=sub[id][j].first;
				if(vis[v])continue;
				ll wi=sub[id][j].second;
				if(dis[v]>dist+tim+wi){
					dis[v]=dist+tim+wi;
					q.push({v,dis[v]});
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		ll g;
		scanf("%lld",&g);
		for(int j=1;j<=g;j++){
			ll v;
			ll wi;
			scanf("%lld %lld",&v,&wi);
			sub[i].push_back({v,wi});
			ll id=++tot[v];
			xian[v][id]={i,j,wi};
		}
	}
	while(q--){
		ll u,v;
		clear();
		scanf("%d %d",&u,&v);
		di(u,v);
		ll ans=w[u]+dis[v]+w[v];
		printf("%lld\n",ans);
	}
	return 0;
}
