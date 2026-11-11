#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int cid,T,n,k,d,dep[N],dfn[N],tot,st[N][22],f[N],tag[N],siz[N],mink,rt;
vector<int> g[N];
vector<int> g2[N];
void dfs1(int u,int fa) {
	st[u][0]=fa;
	dep[u]=dep[fa]+1;
	dfn[u]=++tot;
	for(int v:g[u]) 
		if(v!=fa) dfs1(v,u);
}
int Lca(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	for(int j=20;j>=0;j--) 
		if(dep[st[u][j]]>=dep[v]) u=st[u][j];
	if(u==v) return u;
	for(int j=20;j>=0;j--) 
		if(st[u][j]!=st[v][j]) u=st[u][j],v=st[v][j];
	return st[u][0];
}
bool cmp(int x,int y) {
	return dfn[x]<dfn[y];
}
void dfs2(int u,int fa) {
	f[u]=dep[u];
	for(int v:g[u]) 
		if(v!=fa) dfs2(v,u),f[u]=max(f[u],f[v]);
	if(f[u]-dep[u]>=d) f[u]=0,tag[u]=1;
}
void dfs3(int u,int fa) {
	siz[u]=1;
	for(int v:g2[u]) {
		if(v==fa) continue;
		dfs3(v,u);
		siz[u]+=siz[v]+(dep[v]-dep[u]-1);
	} 
}
void dfs4(int u,int fa) {
	mink=min(mink,siz[rt]-(dep[u]-dep[fa]-1));
	for(int v:g2[u]) 
		if(v!=fa) dfs4(v,u);
}
void dfs5(int u,int fa) {
	f[u]=dep[u];
	for(int v:g[u]) 
		if(v!=fa) dfs2(v,u),f[u]=max(f[u],f[v]);
}
bool check(int mid) {
	d=mid;
	for(int i=1;i<=n;i++) tag[i]=siz[i]=0,g2[i].clear();
	dfs2(1,0);
	vector<int> vec;
	for(int i=1;i<=n;i++) 
		if(tag[i]) vec.push_back(i);
	vector<int> vec1=vec;
	sort(vec1.begin(),vec1.end(),cmp);
	vector<int> vec2=vec1;
	for(int i=1;i<vec1.size();i++) {
		int u=vec1[i-1],v=vec1[i];
		int lca=Lca(u,v);
		vec2.push_back(lca);
	}
	sort(vec2.begin(),vec2.end());
	vec2.erase(unique(vec2.begin(),vec2.end()),vec2.end());
	sort(vec2.begin(),vec2.end(),cmp);
	for(int i=1;i<vec2.size();i++) {
		int u=vec2[i-1],v=vec2[i];
		int lca=Lca(u,v);
		g2[v].push_back(lca);
		g2[lca].push_back(v);
	}	
	if(vec2.empty()) return true;
	rt=vec2[0];
	dfs3(rt,0);
	mink=siz[rt];
	dfs4(rt,0);
	return mink<=k;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cid>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=2,u,v;i<=n;i++) {
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1,0);
		for(int j=1;j<=20;j++) 
			for(int i=1;i<=n;i++) 
				st[i][j]=st[st[i][j-1]][j-1];
		int l=1,r=n,ans=0;
		while(l<=r) {
			int mid=(l+r)/2;
			if(check(mid)) ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) g[i].clear();
	}
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
