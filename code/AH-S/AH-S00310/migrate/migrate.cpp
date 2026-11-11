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
LL c,T,n,d,x[N],dis[N],vis[N],cnt[N];
vector<Node> G[N];
void djs(LL u){
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	memset(dis,0x3f,sizeof dis);
	priority_queue<Node> pq;
	dis[u]=0;
	pq.push({u,0});
	while(!pq.empty()){
		u=pq.top().u;pq.pop();
		//if(vis[u]) continue;
		//vis[u]=1;
		for(LL i=0;i<((LL)G[u].size());i++){
			LL v=G[u][i].u,w=G[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				cnt[v]=1;
				pq.push({v,dis[v]});
			}else if(dis[u]+w==dis[v])cnt[v]++;//cout<<"@";
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		LL ans=0;
		scanf("%lld%lld",&n,&d);
		for(LL i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			for(LL j=1;j<i;j++){
				if(abs(x[i]-x[j])<=d){
					G[i].push_back({j,1});
					G[j].push_back({i,1});
				}
			}
		}
		for(LL i=1;i<=n;i++){
			djs(i);
			for(LL j=1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}

