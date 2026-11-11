#include<bits/stdc++.h>
#define N 1000010
using namespace std;
int T,n,k,ans;
vector<int> G[N];
struct DSU{
	int fa[N];
	void init() { for(int i=1;i<=n;++i) fa[i]=i; }
	int find(int x) { return fa[x]==x? fa[x]:(fa[x]=find(fa[x])); }
	void merge(int x,int y) { find(x)^find(y)? fa[find(x)]=find(y):0; }
}dsu;
int minx[N],dep[N];
void dfs(int u,int fa){
	for(auto v:G[u]){
		if(v==fa) continue;
		minx[v]=min(minx[v],dep[u]+1);
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
void work(){
	for(int i=1;i<=n;++i) G[i].clear();
	scanf("%d%d",&n,&k); ans=0x3f3f3f3f;
	for(int i=1;i<n;++i){
		int u,v; scanf("%d%d",&u,&v);
		G[u].push_back(v); G[v].push_back(u);
	}
	for(int i=1;i<(2<<n);++i){
		if(__builtin_popcount(i)!=k) continue;
		dsu.init();
		for(int j=1;j<=n;++j){
			if(!(i>>j-1&1)) continue;
			for(auto k:G[j]){
				if(!(i>>k-1&1)) continue;
				dsu.merge(j,k);
			}
		}
		int tot=0;
		for(int j=1;j<=n;++j){
			if(!(i>>j-1&1)) continue;
			if(dsu.fa[j]==j) ++tot;
		}
		if(tot>2) continue;
		for(int j=1;j<=n;++j) minx[j]=0x3f3f3f3f, dep[j]=0;
		for(int j=1;j<=n;++j){
			if(!(i>>j-1)&1) continue;
			dep[j]=0; minx[j]=0; dfs(j,0);
		}
		int maxn=0;
		for(int j=1;j<=n;++j) maxn=max(maxn,minx[j]);
		ans=min(ans,maxn);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%*d%d",&T);
	while(T--) work();
	return 0;
}
