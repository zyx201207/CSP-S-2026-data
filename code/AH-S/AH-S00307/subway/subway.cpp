#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500005],k[505],a,aa,t,tt,x,y,dis[500005];
bool vis[500005];
struct node{
	ll v,d;
	bool operator <(const node &rhs)const{
		return d>rhs.d;
	}
};
vector<node>G[500005];
void Dijkstra(ll s){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	priority_queue<node>q;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		ll v=q.top().v,d=q.top().d;q.pop();
		if(vis[v])continue;
		vis[v]=true;
		for(ll i=0;i<G[v].size();i++){
			ll &dv=G[v][i].v;
			if(!vis[dv]&&dis[v]+G[v][i].d<dis[dv])
				dis[dv]=dis[v]+G[v][i].d,q.push({dv,dis[dv]});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(c>=7&&c<=11){
		for(ll i=1;i<=m;i++)scanf("%lld",w+i);
		for(ll i=1;i<=n;i++){
			scanf("%lld",k+i);
			if(k[i]==2){
				scanf("%lld%lld%lld%lld",&a,&t,&aa,&tt);
				G[a].push_back({aa,t+tt});
				G[aa].push_back({a,t+tt});
			}
		}while(q--){
			scanf("%lld%lld",&x,&y);
			Dijkstra(x);
			printf("%lld\n",w[x]+w[y]+dis[y]);
		}
	}
	return 0;
}
