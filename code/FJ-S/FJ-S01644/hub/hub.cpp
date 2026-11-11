#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <assert.h>
#define fin(f) freopen(f,"r",stdin)
#define fout(f) freopen(f,"w",stdout)
#define fo(i,l,r) for(int i=(l);i<=(r);i++)
#define of(i,r,l) for(int i=(r);i>=(l);i--)
#define debug cerr<<"["<<__LINE__<<"] "
#define pb push_back
#define endl '\n'
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
vector<int>g[N];
int dep[N];
int p,q;
void dfs1(int u,int fa) {
	dep[u]=dep[fa]+1;
	if(dep[u]>dep[p]) p=u;
	for(int v:g[u]) if(v!=fa)
		dfs1(v,u);
}
int pre[N];
void dfs2(int u,int fa) {
	dep[u]=dep[fa]+1;
	pre[u]=fa;
	if(dep[u]>dep[q]) q=u;
	for(int v:g[u]) if(v!=fa)
		dfs2(v,u);
}
vector<int>len;
bool inlen[N];
int l[N];
void dfs3(int u,int fa) {
	if(inlen[u]) {
		if(pre[u]) dfs3(pre[u],u);
		for(int v:g[u]) if(v!=fa&&v!=pre[u]) {
			dfs3(v,u);
			l[u]=max(l[u],l[v]+1);
		}
	} else {
		for(int v:g[u]) if(v!=fa) {
			dfs3(v,u);
			l[u]=max(l[u],l[v]+1);
		}
	}
}
int pt[N],m;
int n;
bool check(int lim) {
	int x=1;
	int maxl=0;
	for(;x<=m;x++) {
		maxl=max(maxl,l[pt[x]]);
		if(maxl>lim) {
			x--;
			break;
		}
		maxl++;
	}
	int y=m;
	maxl=0;
	for(;y>=1;y--) {
		maxl=max(maxl,l[pt[y]]);
		if(maxl>lim) {
			y++;
			break;
		}
		maxl++;
	}
	if(x>=y) return 1;
	fo(i,x+1,y-1) {
		int minl=min(i-x,y-i)+l[pt[i]];
		if(minl>lim) return 0;
	}
	return 1;
}
void work() {
	int k;cin>>n>>k;
	fo(i,1,n-1) {
		int u,v;cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,0);
	fo(i,1,n) dep[i]=0;
	dfs2(p,0);
	int maxlen=dep[q];
	if(k==1) cout<<maxlen/2<<endl;
	else {
		for(int x=q;x;x=pre[x]) {
			len.pb(x);
			pt[++m]=x;
			inlen[x]=1;
		}
		dfs3(q,0);
		int l=0,r=maxlen/2+1;
		while(l<r) {
			int mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		cout<<r<<endl;
	}
	fo(i,1,n) dep[i]=0;
	fo(i,1,m) pt[i]=0;
	m=0;
	len.clear();
	fo(i,1,n) inlen[i]=0;
	fo(i,1,n) l[i]=0;
	fo(i,1,n) pre[i]=0;
	p=q=0;
	fo(i,1,n) g[i].clear();
}
int main() {
	fin("hub.in");fout("hub.out");
	ios::sync_with_stdio(0);cin.tie(nullptr);
	int c,t;cin>>c>>t;
	while(t--) work();
	return 0;
}