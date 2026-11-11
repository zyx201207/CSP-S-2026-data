#include <bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pb push_back
typedef long long ll;
const int N=1e6+6;
ll rd() {
	ll x=0,f=1; char c=gc;
	for(;c<'0'||c>'9';c=gc)if(c=='-')f=-1;
	for(;c>='0'&&c<='9';x=x*10+c-'0',c=gc);
	return x*f;
}
int C,T,n,k,U[N],V[N],lg[N],dep[N],f[N][22],fa[N];
vector<int> e[N];
bool tag[N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y) {
	x=find(x); y=find(y);
	if(x!=y) fa[x]=y;
}
void dfs(int u,int anc) {
	f[u][0]=anc; dep[u]=dep[anc]+1;
	for(int v:e[u]) if(v!=anc) dfs(v,u);
}
int lca(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) x=f[x][lg[dep[x]-dep[y]]];
	if(x==y) return x;
	for(int k=lg[dep[x]];k>=0;k--)
		if(f[x][k]!=f[y][k]) x=f[x][k],y=f[y][k];
	return f[x][0];
}
int dis(int x,int y) {return dep[x]+dep[y]-2*dep[lca(x,y)];}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for(int i=2;i<N;i++) lg[i]=lg[i/2]+1;
	for(C=rd(),T=rd();T;T--) {
		n=rd(); k=rd();
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++) {
			U[i]=rd(); V[i]=rd();
			e[U[i]].pb(V[i]); e[V[i]].pb(U[i]);
		}
		dfs(1,0);
		for(int j=1;j<=lg[n];j++) for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
		if(C<=3) {
			int ans=n;
			for(int msk=0;msk<(1<<n);msk++) {
				if(__builtin_popcount(msk)!=k) continue;
				for(int i=1;i<=n;i++) {
					if(msk&(1<<(i-1))) tag[i]=1;
					else tag[i]=0;
				}
				for(int i=1;i<=n;i++) fa[i]=(tag[i]?i:0);
				for(int i=1;i<n;i++)
					if(tag[U[i]]&&tag[V[i]]) merge(U[i],V[i]);
				int cnt=0;
				for(int i=1;i<=n;i++) if(fa[i]==i) cnt++;
				if(cnt>2) continue;
				int res=0;
				for(int i=1;i<=n;i++) {
					int dist=n;
					for(int j=1;j<=n;j++) {
						if(!tag[j]) continue;
						dist=min(dist,dis(i,j));
					}
					res=max(res,dist);
				}
				ans=min(ans,res);
			}
			cout<<ans<<'\n';
		} else if(C==7||C==11||C==12) { // k=2
			
		} else if(C==13||C==14) {
			if(k==n) cout<<0<<'\n';
			else if(k>n/2) cout<<1<<'\n';
			else cout<<(n/2-k+3)/4+1<<'\n';
		}
	}
	return 0;
}
