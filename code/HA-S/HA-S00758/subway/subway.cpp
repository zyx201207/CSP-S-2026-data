#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,k[500005];
ll tot;
ll to[500005],vail[500005],nxt[500005],h[500005];
ll dis[500005];
bool vis[500005];
priority_queue< pair<ll,ll> >q1;
struct inf{
	ll g,t;
}l[500005];
void add(ll u,ll v,ll w){
	to[++tot]=v;
	vail[tot]=w;
	nxt[tot]=h[u];
	h[u]=tot;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&k[i]);
	}
	for(int i=1;i<=n;i++){
		ll s;
		scanf("%lld",&s);
		for(int j=1;j<=s;j++){
			scanf("%lld%lld",&l[j].g,&l[j].t);
			for(int p=1;p<j;p++){
				add(l[j].g,l[p].g,l[j].t+l[p].t);
				add(l[p].g,l[j].g,l[j].t+l[p].t);
			}
		} 
	}
	while(q--){
		ll s,t;
		scanf("%lld%lld",&s,&t);
		for(int i=1;i<=m;i++)dis[i]=1e18,vis[i]=0;
		dis[s]=0;
		q1.push({0,s});
		while(!q1.empty()){
			ll u=q1.top().second;
			q1.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int i=h[u];i!=0;i=nxt[i]){
				ll v=to[i];
				if(!vis[v]&&dis[v]>dis[u]+vail[i]){
					dis[v]=dis[u]+vail[i];
					q1.push({-dis[v],v});
				}
			}
		}
		cout<<dis[t]+k[s]+k[t]<<'\n';
	}
	return 0;
}//36-44fen
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
