#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e6+10,M=5e5+10,D=5e5+10;
LL c,n,t,cnt,minn=1e18,d,dis[10005][10005],a[N];
bool vis[N];
struct Node{
	LL u,ti;
	bool operator<(const Node& rhs)const{
		return rhs.ti<ti;
	}
};
vector<Node> G[N],f[N];
void djs(LL x){
	memset(vis,0,sizeof vis);
	priority_queue<Node> pq;
	pq.push({x,0});
	dis[x][x]=0;
	while(!pq.empty()){
		Node u=pq.top();pq.pop();
		vis[u.u]=1;
		for(Node v:G[u.u]){
			if(!vis[v.u]&&dis[x][v.u]>dis[x][u.u]+v.ti){
				dis[x][v.u]=dis[x][u.u]+v.ti;
				pq.push({v.u,dis[x][v.u]});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		memset(dis,0x3f,sizeof dis);
		scanf("%lld%lld",&n,&d);
		for(LL i=1;i<=n;++i)	scanf("%lld",&a[i]);
		for(LL i=1;i<=n;++i)
		for(LL j=1;j<=n;++i)	G[i].push_back({j,abs(a[i]-a[j])});
		for(LL i=1;i<=n;++i){
			djs(i);
			for(LL j=1;j<=n;++j)	minn=min(minn,dis[i][j]);
			for(LL j=1;j<=n;++j)	cnt+=(dis[i][j]==minn);
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
