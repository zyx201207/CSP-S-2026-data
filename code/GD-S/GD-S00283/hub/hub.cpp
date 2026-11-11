#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e6+5,INF=0x3f3f3f3f;
int c,t,n,k,f[N],dep[N];
vector<int>g[N];
void build(int u,int dad){
	f[u]=dad;dep[u]=dep[dad]+1;
	for (auto v:g[u]){
		if (v==dad) continue;
		build(v,u);
	}
}
int lca(int u,int v){
	if (dep[u]<dep[v]) swap(u,v);
	while (dep[u]!=dep[v]) u=f[u];
	while (u!=v) {u=f[u];v=f[v];}
	return u;
}
int dist(int u,int v) {return dep[u]+dep[v]-2*dep[lca(u,v)];}
int s[N],ans=INF;
int run(){
	int ans=0;
	for (int i=1;i<=k;++i) for (int j=i+1;j<=k;++j) ans+=(f[s[i]]!=s[j]&&f[s[j]]!=s[i]);
	return ans;
}
bool vis[N];
void dfs(int u){
	if (u>k){
		if (run()>2) return;
		int cnt=0;
		for (int i=1;i<=n;++i){
			int d=INF;
			for (int j=1;j<=k;++j) d=min(d,dist(i,s[j]));
			cnt=max(cnt,d);
		}
		ans=min(ans,cnt);
		return;
	}
	for (int i=1;i<=n;++i){
		if (vis[i]) continue;
		vis[i]=1;s[u]=i;
		dfs(u+1);
		vis[i]=0;s[u]=0;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--){
		for (int i=1;i<=n;++i) {g[i].clear();f[i]=s[i]=dep[i]=0;}
		ans=INF;
		scanf("%d%d",&n,&k);
		for (int i=1;i<n;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		build(1,0);
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
