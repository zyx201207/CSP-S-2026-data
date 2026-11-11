#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct rr{
	ll u,len;
	bool operator > (const rr& x)const{
		return len>x.len;
	}
};
vector<rr>G[50010];
bool vis[50010];
ll mem[1010][1010];
ll w[50010],k[510],a[50010],t[50010],dis[50010];
ll c,n,m,d,q;
void Djs(ll u){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<rr,vector<rr>,greater<rr>>pq;
	dis[u]=0;
	pq.push({u,0});
	while(!pq.empty()){
		u=pq.top().u;
		pq.pop();
		vis[u]=1;
		for(auto v:G[u]){
			if(!vis[v.u] && dis[v.u]>dis[u]+v.len){
				dis[v.u]=dis[u]+v.len;
				pq.push({v.u,dis[v.u]});
			}
		}
	}
}
void solve1(){
	for(ll i=1;i<=n;i++){
		scanf("%lld",k+i);
		for(ll j=1;j<=k[i];j++){
			scanf("%lld %lld",&a[j],&t[j]);
			if(j>1){
				ll len=t[j-1]+t[j];
				G[a[j-1]].push_back({a[j],len});
				G[a[j]].push_back({a[j-1],len});
			} 
		}
	}
	for(ll i=1;i<=m;i++){
		Djs(i);
		for(ll j=1;j<=m;j++){
			mem[i][j]=dis[j]+w[i]+w[j];
		}
	}
	ll x,y;
	while(q--){
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",mem[x][y]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++) scanf("%lld",w+i);
	solve1();
	return 0;
}
