#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5*1e5+10;
ll c,n,m,d,q1;
ll dist[maxn];
bool vis[maxn];
priority_queue<pair<ll,ll> > q;
struct Node{
	ll x;
	ll num;
};
vector<Node> g[maxn];
ll lu[2*10010][501];
ll w[maxn];
ll a[maxn];
void dijkstra(ll s){
	for(ll i=1;i<=m;i++) dist[i]=0x7f7f7f7f;
	for(ll i=1;i<=m;i++) vis[i]=0;
	dist[s]=0;
	q.push({0,s});
	while(!q.empty()){
		ll t=q.top().second;
		q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(ll i=0;i<g[t].size();i++){
			ll minnum=lu[g[t][i].x][g[t][i].num]+lu[t][g[t][i].num];
//			cout<<minnum<<" ";
			minnum+=w[g[t][i].x]+w[t];
			if(t!=s) minnum-=w[t];
			if(dist[g[t][i].x]>dist[t]+minnum-1&&t!=s){
				dist[g[t][i].x]=dist[t]+minnum-1;
				q.push({-dist[g[t][i].x],g[t][i].x});
			}
			else if(dist[g[t][i].x]>dist[t]+minnum){
				dist[g[t][i].x]=dist[t]+minnum;
				q.push({-dist[g[t][i].x],g[t][i].x});
			}
		}
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q1);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=n;j++){
			lu[i][j]=0x7f7f7f7f;
		}
	}
	for(ll i=1;i<=n;i++){
		ll num;
		scanf("%lld",&num);
		for(ll j=1;j<=num;j++){
			ll t;
			scanf("%lld%lld",&a[j],&t);
			lu[a[j]][i]=t;
		}
		for(ll j=1;j<=num;j++){
			for(ll k=1;k<=num;k++){
				g[a[j]].push_back({a[k],i});
			}
		}
	}
	for(ll i=1;i<=q1;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		dijkstra(x);
//		for(ll j=1;j<=m;j++) printf("%lld ",dist[j]);
//		printf("\n");
		printf("%lld\n",dist[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
