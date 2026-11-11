#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int ans=0,f=1;
	while(c<48||c>57) (c==45?f=-1:1),c=getchar();
	while(c>=48&&c<=57) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}
const int N=110;
int n,f[N][N],fa[N],k,vis[N];
vector<int>g[N];
int find(int x){if (fa[x]==x) return x;return fa[x]=find(fa[x]);}
inline void solve(){
	n=read(),k=read();
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) f[i][j]=1e18;
	for (int i=1;i<=n;i++) f[i][i]=0,fa[i]=i,g[i].clear();
	for (int i=1,u,v;i<n;i++) u=read(),v=read(),g[u].push_back(v),g[v].push_back(u),f[u][v]=f[v][u]=1;
	int ans=1e18;
	for (int k=1;k<=n;k++) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for (int i=0;i<(1<<n);i++) if (__builtin_popcountll(i)==k){
		for (int i=1;i<=n;i++) fa[i]=i,vis[i]=0;
		for (int j=1;j<=n;j++) if (i>>j-1&1) vis[j]=1;
		for (int j=1;j<=n;j++) if (vis[j]) for (auto k:g[j]) if (vis[k]) fa[find(j)]=find(k);
		int cnt=0;
		for (int j=1;j<=n;j++) if (vis[j]) cnt+=(fa[j]==j);
		if (cnt>2) continue;
//		puts("dd");
		int sum=0;
		for (int i=1;i<=n;i++){
			int mx=1e18;
			for (int j=1;j<=n;j++) if (vis[j]) mx=min(mx,f[i][j]);
			sum=max(sum,mx);
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}
main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read();int T=read();
	while(T--) solve();
	return 0;
}

