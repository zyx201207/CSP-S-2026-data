#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5000;
int n,m,q;
int w[N/2];
int head[N],ne[N],val[N],to[N],idx;
void adde(int x,int y,int z){
	to[++idx]=y;
	ne[idx]=head[x];
	val[idx]=z;
	head[x]=idx; 
}
int st[N/10],ed[N/10];
struct node{
	int end,id;
	bool operator < (const node &nd) const{
		return id>nd.id;
	}
};
vector<node>e[N/2];
int awa[N/10],ans[N/10];
int dis[N/2],vis[N/2];
priority_queue <node> Q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",w+i);
	for(int i=1,k;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1,a,t;j<=k;j++){
			scanf("%lld%lld",&a,&t);
			adde(m+i,a,t);adde(a,m+i,t);
		}
	}
	m+=n;
	for(int i=1;i<=q;i++) scanf("%lld%lld",st+i,ed+i);
	for(int i=1;i<=q;i++) e[st[i]].push_back({ed[i],i}),awa[++awa[0]]=st[i];
	for(int i=1;i<=awa[0];i++){
		int be=awa[i];
		for(int j=1;j<=m;j++) dis[j]=1e18,vis[j]=0;
		dis[be]=0;Q.push({be,0});
		while(!Q.empty()){
			int u=Q.top().end;Q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int i=head[u];i;i=ne[i]){
				int v=to[i];
				dis[v]=min(dis[v],dis[u]+val[i]);
				if(!vis[v]) Q.push({v,dis[v]});
			}
		}
		for(int j=0;j<e[be].size();j++) ans[e[be][j].id]=w[be]+w[e[be][j].end]+dis[e[be][j].end];
	}
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
}
