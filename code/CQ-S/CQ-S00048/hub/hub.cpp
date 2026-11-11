#include<bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define drep(i,r,l) for(int i=(r); i>=(l); --i)
using namespace std;
#define pb push_back
const int N=1e6+5,M=1e5;
int n,k,S,T,f[N],g[N],p[N],fa[N],siz[N];
vector<int>E[N];
void DFS(int u) {
	siz[u]=1,f[u]=0;
	for(int v:E[u]) if(v^fa[u]) fa[v]=u,DFS(v),f[u]+=f[v]+siz[v],siz[u]+=siz[v];
}
void CRT(int u) {
	for(int v:E[u]) if(v^fa[u]) g[v]=g[u]+f[u]-f[v]-siz[v]+n-siz[v],CRT(v);
}
struct {
	int A,B,P,Q,now,mid,dep[N],pa[N],mxd[N];
	inline void find(int u,int fa) {
		if(u==B) return;
		for(int v:E[u]) if(v^fa&&v^B) pa[v]=u,dep[v]=dep[u]+1,find(v,u);
		if(dep[u]>dep[T]) T=u;
	}
	void init(int u,int v) {
		A=u,B=v;
		T=0,dep[A]=0,find(A,B),P=T;
		dep[P]=pa[P]=T=0,find(P,0),Q=T;
//		cout<<A<<' '<<B<<'\n'<<P<<' '<<Q<<'\n';
	}
	inline void calc(int u,int fa) {
		if(u==B) return;
		mxd[u]=0;
		for(int v:E[u]) if(v^fa&&v^B) calc(v,u),mxd[u]=max(mxd[u],mxd[v]+1);
		if(mxd[u]>=mid) ++now;
	}
	int chk(int m) {
		int u=Q,lst=0; now=0,mid=m;
		while(u) {
			if(min(dep[u],dep[Q]-dep[u])>=m) {
				for(int v:E[u]) if(v^fa[u]&&v^lst&&v^B) calc(v,u);
				++now;
			}
			lst=u,u=pa[u];
		}
		return max(now,1);
	} 
} X,Y;
int calc() {
	int l=0,r=n,m;
	while(l<r) m=l+r>>1,X.chk(m)+Y.chk(m)<=k?r=m:l=m+1;
	return l;
}
void sol() {
	cin>>n>>k,S=N;
	rep(i,1,n) E[i].clear();
	rep(i,2,n) {int u,v; cin>>u>>v,E[u].pb(v),E[v].pb(u);}
	DFS(1),g[1]=0,CRT(1);
//	rep(i,1,n) cout<<f[i]<<' '<<g[i]<<'\n';
	iota(p,p+n+1,1),sort(p+1,p+n,[](int x,int y) {return f[x]+g[fa[x]]<f[y]+g[fa[y]];});
	rep(t,1,min(M/n,n-1)) X.init(p[t],fa[p[t]]),Y.init(fa[p[t]],p[t]),S=min(S,calc());
	cout<<S<<'\n';
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	FASTIO;
	int _; cin>>_>>_;
	while(_--) sol();
}
