#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4004+5;
vector<int> T[maxn];
int rt,n,m,dis[maxn][maxn],walk[maxn][maxn]; // walk[i][j] : i -> u -> j
void dfs(int u,int f) {
	walk[u][rt]=f;
	dis[rt][u]=dis[rt][f]+1;
	for(int v:T[u]) if(v!=f) {
		dfs(v,u);
	}
}
int dfn[maxn],id[maxn],cur,sz[maxn],fa[maxn],stk[maxn],top,mid,cnt;
bool fil[maxn],mark[maxn];
void dfs2(int u,int f) {
	sz[u]=1; id[u]=++cur; fa[u]=f;
	for(int v:T[u]) if(v!=f) dfs2(v,u),sz[u]+=sz[v];
} 
void dfs3(int u,int f,int col) {
	stk[++top]=u;
	if(top>mid&&!mark[stk[top-mid]]) {
		++cnt;
		if(cnt>m) return;
		mark[stk[top-mid]]=1;
	}
	for(int v:T[u]) if(v!=f&&fil[v]==col) dfs3(v,u,col);
	--top;
}
bool chk() {
//	cout<<"mid-- "<<mid<<'\n';
	for(int u=2;u<=n;++u) {
		int l1=0,l2=0,v=fa[u];
		for(int i=1;i<=n;++i) {
			fil[i]=(id[u]<=id[i]&&id[i]<id[u]+sz[u]);
			if(fil[i]) {
				if(dis[u][i]>dis[u][l1]) l1=i;
			} else if(dis[v][i]>dis[v][l2]) l2=i;
			mark[i]=0;
		}
		int r1=0,r2=0;
		for(int i=1;i<=n;++i) {
			if(fil[i]) {
				if(dis[l1][i]>dis[l1][r1]) r1=i;
			} else if(dis[l2][i]>dis[l2][r2]) r2=i;
		}
		int c1=l1,c2=l2;
		while(dis[l1][c1]<dis[c1][r1]) c1=walk[c1][r1];
		while(dis[l2][c2]<dis[c2][r2]) c2=walk[c2][r2];
//		cout<<u<<" "<<v<<" "<<c1<<" "<<c2<<"\n"
//		<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" "<<dis[l1][c1]<<" "<<dis[l2][c2]<<'\n';
//		for(int i=1;i<=n;++i) cout<<fil[i]<<' '; cout<<'\n';
		if(mid>=max(dis[l1][c1],dis[l2][c2])) return 1;
		mark[c1]=mark[c2]=1; cnt=2; top=0;
		dfs3(c1,0,1); dfs3(c2,0,0);
		if(cnt<=m) return 1;
	}
	return 0;
}
void slv() {
	cin>>n>>m;
	for(int i=1;i<=n;++i) T[i].clear();
	for(int i=1;i<n;++i) {
		int u,v; cin>>u>>v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	if(n==m) {
		cout<<0<<'\n';
		return;
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) walk[i][j]=0;
	for(int i=1;i<=n;++i) {
		rt=i; dis[rt][0]=-1;
		dfs(i,0);
	} 
	cur=0; dfs2(1,0);
	int l=1,r=n-1,ans=n-1;
	while(l<=r) {
		mid=(l+r)>>1;
		if(chk()) {
			ans=mid; r=mid-1;
		} else l=mid+1;
	}
	cout<<ans<<'\n';
}
int main() {
//	system("fc hub.out hub3.ans");
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,T; cin>>c>>T;
	while(T--) slv();
	return 0;
} 
