#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
typedef long long LL;
struct Node{
	LL u,w;
	bool operator <(const Node &rhs) const{
		return w>rhs.w;
	}
};
LL w[N],c,n,m,d,q,vis[N],dis[N],u,ww,s,t,k;
vector<Node> G[N];
void djs(LL u){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	priority_queue<Node> pq;
	dis[u]=0;
	pq.push({u,0});
	while(!pq.empty()){
		u=pq.top().u;pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(LL i=0;i<((LL)G[u].size());i++){
			LL v=G[u][i].u,w=G[u][i].w;
			if(!vis[v]&&dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(LL i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(LL i=1;i<=n;i++){
		scanf("%lld",&k);
		for(LL j=1;j<=k;j++){
			scanf("%lld%lld",&u,&ww);
			G[u].push_back({m+i,ww});
			G[m+i].push_back({u,ww});
		}
	}
	while(q--){
		scanf("%lld%lld",&s,&t);
		djs(s);
		LL ans=dis[t]+w[s]+w[t];
		printf("%lld\n",ans);
	}
	return 0;
}
