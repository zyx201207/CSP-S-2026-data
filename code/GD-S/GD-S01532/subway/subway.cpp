#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int M=2e6;int c,n,m,d,q,ans,w[M],val[M];vector<pii>g[M];
int dij(int x,int y){
	int res=0;
	priority_queue<pii,vector<pii>,greater<pii> >q;
	vector<int>dis(m+5,1e18),pre(m+5,0);
	q.push({0,x}),dis[x]=0;
	while(!q.empty()){
		pii p=q.top();q.pop();
		int d=p.first,u=p.second;
		if(d>dis[u]) continue;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({w,v});
				pre[v]=u;
			}
		}
	}res+=dis[y];
	int u=y;
	while(u!=x){
		u=pre[u];
		res+=val[u];
	}return res;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1,k;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1,a,t;j<=k;j++){
			scanf("%lld%lld",&a,&t);
			if(i==a) val[i]=t;
			else g[i].push_back({a,t}),g[a].push_back({i,k});
		}
	}
	for(int i=1,x,y;i<=q;i++) scanf("%lld%lld",&x,&y),printf("%lld\n",dij(x,y)+w[x]+w[y]);
	return 0;
}
