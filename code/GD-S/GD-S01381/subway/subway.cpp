#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],mi,x,y;
vector<pair<int,int> > g[500005];
vector<pair<int,int> > e[500005];
bool vis[500005];
void dfs(int u,int fa,int tim,int st,int lst){
	if(u==y){
		mi=min(mi,tim);
		return;
	}
	for(auto ed:e[u]){
		int v=ed.first;
		if(v!=lst&&v!=st) dfs(u,fa,tim+g[v][u].second+g[st][u].second,v,st);
	}
	for(auto ed:g[st]){
		int v=ed.first;
		if(v==fa||v==u) continue;
		if(!vis[v]){
			vis[v]=1;
			dfs(v,u,tim+ed.second,st,lst);
			vis[v]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,u,w;j<=k;j++){
			scanf("%d%d",&u,&w);
			g[i].push_back({u,w});
			g[u].push_back({i,w});
			e[u].push_back({i,w});
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		mi=1e9;
		for(auto ed:g[x]){
			int state=ed.first;
			dfs(x,0,w[x]+w[y],state,0);
		}
		printf("%d\n",mi);
	}
	return 0;
}
