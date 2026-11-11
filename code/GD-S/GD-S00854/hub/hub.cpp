#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 4e3+5;

int n,m,tot;
vector<int> e[N];
int f[N][N];
int st[N],ed[N];
int ans=1e9+7;
int h[N],dep[N],g[N],sc[N];
int c,T;

void dfs(int u,int fa) {
	st[u]=++tot;
	for(int v:e[u]) {
		if(v==fa) continue;
		dfs(v,u);
		if(h[v]+1>sc[u]) sc[u]=h[v]+1;
		if(h[u]<sc[u])swap(h[u],sc[u]);
	}
	f[u][1]=h[u];
	
	for(int v:e[u]) {
		if(v==fa) continue;
		for(int i=m;i>=0;i--) {
			for(int j=0;j<=i;j++) {
				f[u][i]=min({f[u][i],max(f[u][i-j],f[v][j])});
			}
		}
	}
	ed[u]=tot;
}

void DFS(int u,int fa) {
	for(int v:e[u]) {
		if(v==fa) continue;
		g[v]=max(g[u],(h[u]==h[v]+1 ? sc[u] : h[u]))+1;
		for(int i=st[u];i<=st[v]-1;i++) {
			for(int j=st[v];j<=ed[v];j++) {
				for(int p=0;p<=m;p++) {
					ans=min(ans,max({f[i][p],f[j][m-p],dep[i]+dep[j]-2*dep[u]}));
				}
			}
		}
	}
}
int main() {
//	freopen("hub1.in","r",stdin);
//	freopen("hub.out","w",stdout);
	cin>>c>>T;
	cout<<c<<" "<<T<<"\n";
//	while(T--) {
//		cin>>n>>m;
//		
//		tot=0;
//		memset(f,0,sizeof(f));
//		for(int i=1;i<=n;i++)
//			e[i].clear();
//		for(int i=1;i<n;i++) {
//			int u,v;
//			cin>>u>>v;
//			e[u].push_back(v);
//			e[v].push_back(u);
//		}
//		
//		dfs(1,0);
//		DFS(1,0);
//		
////		cout<<ans<<'\n';
//	}
	return 0;
}
