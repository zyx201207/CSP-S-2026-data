#include <bits/stdc++.h>
#define fo(i,l,r) for(int i(l); i<=(r); ++i)
#define fu(i,l,r) for(int i(l); i<(r); ++i)
#define fd(i,l,r) for(int i(l); i>=(r); --i)
#define File "hub"
#define pb push_back
#define il inline
#define sz(x) (int((x).size()))
using namespace std;
using ll=long long;
const int N=1e6+5,inf=1e9;
int tid,n,m;
vector<int> e[N];
int dep[N],d[N],fa[N];
int dfc,dfn[N],pos[N],low[N];
array<int,2> g[N];
int f[N],s[N];
int st[20][N];
array<int,2> c[N][2];
void ins(array<int,2> *x,array<int,2> y) {
	if(y>x[0]) x[1]=x[0],x[0]=y;
	else if(y>x[1]) x[1]=y;
}
void dfs2(int u,int p) {
	c[u][0]={0,u};
	c[u][1]={-inf,-1};
	for(auto v : e[u]) if(v!=p) {
		dfs2(v,u);
		ins(c[u],{c[v][0][0]+1,v});
	}
}
void dfs3(int u,int p) {
	for(auto v : e[u]) if(v!=p) {
		ins(c[v],{c[u][c[u][0][1]==v][0]+1,u});
		dfs3(v,u);
	}
}
void dfs(int u,int p) {
	fa[u]=p;
	dfn[u]=++dfc,pos[dfn[u]]=u;
	d[u]=0;
	for(auto v : e[u]) if(v!=p) dep[v]=dep[u]+1,dfs(v,u),d[u]=max(d[u],d[v]+1);
	low[u]=dfc;
}
struct Diam {
	int fa[N],dep[N];
	void dfs(int u,int p) {
		fa[u]=p;
		for(auto v : e[u]) if(v!=p) {
			dep[v]=dep[u]+1;
			dfs(v,u);
		}
	}
	array<int,2> find() {
		dep[1]=0,dfs(1,0);
		int x=max_element(dep+1,dep+n+1)-dep;
		dep[x]=0,dfs(x,0);
		int y=max_element(dep+1,dep+n+1)-dep;
		return {x,y};
	}
} di;
int calc(int x,int y) {
	if(fa[x]==y) swap(x,y);
	dfs2(x,y),dfs3(x,y);
	dfs2(y,x),dfs3(y,x);
	fo(j,0,n-1) f[j]=s[j]=0;
	fo(u,1,n) {
		int i=c[u][1][0];
		if(i<0) continue;
		++f[i];
		s[i]|=dfn[y]<=dfn[u]&&dfn[u]<=low[y]?2:1;
	}
	fd(j,n-2,0) f[j]+=f[j+1],s[j]|=s[j+1];
	int res=n;
	fd(j,n-1,0) {
		if(f[j]+!(s[j]&1)+!(s[j]&2)>m) break;
		res=j;
	}
	return res;
}
int calc2(const vector<array<int,2>> &x) {
	if(!sz(x)) return n;
	int l=0,r=sz(x)-1;
	while(l<r) {
		int mid=l+r>>1;
		int L=calc(x[mid][0],x[mid][1]),R=calc(x[mid+1][0],x[mid+1][1]);
		if(L>R) l=mid+1;
		else r=mid;
	}
	return calc(x[l][0],x[l][1]);
}
il int lca(int x,int y) {
	if(x==y) return x;
	x=dfn[x],y=dfn[y];
	if(x>y) swap(x,y);
	int k=__lg(y-x);
	return pos[min(st[k][x+1],st[k][y-(1<<k)+1])];
}
il int dis(int x,int y) {
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
struct DM {
	int x,y,d;
} dm[N],pm[N],sf[N];
il bool operator<(const DM &a,const DM &b) {
	return a.d<b.d;
}
il DM IM(int x,int y) {
	return {x,y,dis(x,y)};
}
DM operator+(const DM &a,const DM &b) {
	return max(max(a,b),max(max(IM(a.x,b.x),IM(a.x,b.y)),max(IM(a.y,b.x),IM(a.y,b.y))));
}
void dfs4(int u,int p) {
	dm[u]={u,u,0};
	for(auto v : e[u]) if(v!=p) {
		dfs4(v,u);
		dm[u]=dm[u]+dm[v];
	}
}
void solve() {
	cin>>n>>m;
	fo(i,1,n-1) {
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
		g[i]={u,v};
	}
	dfs(1,0);
	if(tid<=10) {
		int ans=n-1;
		fo(i,1,n-1) ans=min(ans,calc(g[i][0],g[i][1]));
		cout<<ans<<'\n';
		return ;
	}
	if(11<=tid&&tid<=12) {
		fo(i,2,n) st[0][dfn[i]]=dfn[fa[i]];
		fu(j,1,20) fo(i,1,n-(1<<j)+1) st[j][i]=min(st[j-1][i],st[j-1][i+(1<<j-1)]);
		dfs4(1,0);
		pm[1]={pos[1],pos[1],0};
		fo(i,2,n) pm[i]=pm[i-1]+DM{pos[i],pos[i],0};
		sf[n]={pos[n],pos[n],0};
		fd(i,n-1,1) sf[i]=sf[i+1]+DM{pos[i],pos[i],0};
		int ans=n;
		fo(i,1,n-1) {
			auto [x,y]=g[i];
			if(fa[x]==y) swap(x,y);
			int d=dm[y].d;
			DM u={x,x,0};
			if(1<dfn[y]) u=u+pm[dfn[y]-1];
			if(low[y]<n) u=u+sf[low[y]+1];
			d=max(d,u.d);
			ans=min(ans,d+1>>1);
		}
		cout<<ans<<'\n';
		return ;
	}
	if(13<=tid&&tid<=14) {
		auto [x,y]=di.find();
		vector<array<int,2>> h;
		for(int u=y; u!=x; u=di.fa[u]) h.pb({u,di.fa[u]});
		vector<array<int,2>> hh[2];
		fu(i,0,sz(h)) hh[i&1].pb(h[i]);
		cout<<min(calc2(hh[0]),calc2(hh[1]))<<'\n';
		return ;
	}
	int ans=n-1;
	auto [x,y]=di.find();
	for(int u=y; u!=x; u=di.fa[u]) {
		int t=calc(u,di.fa[u]);
		ans=min(ans,t);
	}
	cout<<ans<<'\n';
}
void clear() {
	fo(i,1,n) e[i].clear();
	dfc=0;
}
int main() {
	freopen(File".in","r",stdin);
	freopen(File".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int Tc;
	cin>>tid>>Tc;
	while(Tc--) solve(),clear();
	return 0;
}