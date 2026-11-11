#include <iostream>
#include <cstdio>
#include <vector>
#define N 2000010
using namespace std;
int c,t,n,k;
vector<int> G[N];
int deep[N],gs[N],tgs[N],fa[N][22],tt[N],dp[N];
void dfs(int u,int f) {
	for (auto v:G[u]) {
		if (v!=f) {
			deep[v]=deep[u]+1;
			dfs(v,u);
			fa[v][0]=u;
			if (gs[v]+1>gs[u]) {
				gs[u]=gs[v]+1;
				tgs[u]=gs[u];
			} else if (gs[v]+1>tgs[u]) {
				tgs[u]=gs[v]+1;
			}
		}
	}
}
void dfs2(int u,int fa,int dd) {
	if (gs[u]>=dd) tt[u]=1;
	for (auto v:G[u]) {
		if (v!=fa) {
			dfs2(v,u,dd);
			tt[u]+=tt[v];
		}
	}
}
int LCA(int x,int y) {
	if (deep[x]<deep[y]) swap(x,y);
	for (int j=21;j>=0;j--)
		if (deep[fa[x][j]]>=deep[y]) x=fa[x][j];
	if (x==y) return x;
	for (int j=21;j>=0;j--)
		if (fa[x][j]!=fa[y][j]) x=fa[x][j],y=fa[y][j];
	return fa[x][0];
}
bool is;
int len(int x,int y) {
	return deep[x]+deep[y]-2*deep[LCA(x,y)];
}
void dfs3(int u,int fa,int d1,int d2,int dd) {
	for (auto v:G[u]) {
		if (v!=fa&&v!=d1&&v!=d2) {
			dfs3(v,u,d1,d2,dd);
		}
	}
	if (min(len(u,d1),len(u,d2))>=dd) is=1;
//	cout << u << " " << d1 << " " << d2 << " " << min(len(u,d1),len(u,d2)) << " " << dd << "\n";
}
bool check(int dd) {
	for (int ii=1;ii<=n;ii++) {
		for (int u=1;u<=n;u++) deep[u]=gs[u]=tgs[u]=fa[u][0]=tt[u]=0;
		dfs(ii,0);
		for (int i=1;i<=n;i++) tt[i]=0;
		dfs2(ii,0,dd);
		for (int j=1;j<=21;j++)
			for (int i=1;i<=n;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		for (int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				if (LCA(i,j)!=i&&LCA(i,j)!=j) {
					int ps=tt[i]+tt[j];
					if (ps<=k) {
						is=0;
						dfs3(ii,0,i,j,dd);
	//					cout << ii << " " << dd << " " << i << " " << j << " ";
	//					cout << !is << "\n";
						if (is==0) return true;
					}
				} else {
					
				}
			}
		}
	}
	return false;
}
int main(void) {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	for (;t--;) {
		cin >> n >> k;
		for (int i=1;i<=n;i++) G[i].clear();
		for (int u,v,i=1;i<n;i++) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int l=0,r=n;
		for (;l<=r;) {
			int mid=(l+r)>>1;
			if (check(mid)) r=mid-1;
			else l=mid+1;
		}
		cout << l << "\n";
	}
	return 0;
}
