#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
#define infile(filename) freopen(filename".in","r",stdin)
#define outfile(filename) freopen(filename".out","w",stdout)
#define usefile(filename) infile(filename),outfile(filename)
using namespace std; typedef long long ll; typedef unsigned long long ull;
inline char gc() { static const int BUF=1<<20; static char ch[BUF]={},*l=ch,*r=ch; return (l==r&&(r=(l=ch)+fread(ch,1,BUF,stdin),l==r))?EOF:*l++; }
template <typename T> void read(T &a) { static char ch,fushu; a=fushu=0; do ch=gc(); while(ch!='-'&&(ch<48||ch>57)); if(ch=='-') fushu=1,ch=gc(); do a=(a<<1)+(a<<3)+(ch^48),ch=gc(); while(ch>47&&ch<58); if(fushu) a=-a; return ; }
template <typename T,typename ...Args> void read(T &a,Args &...args) { read(a),read(args...); }
template <typename T> void ckmax(T &a,T b) { if(a<b) a=b; }
template <typename T> void ckmin(T &a,T b) { if(b<a) a=b; }
const int N=1000099,LogN=21,inf=1e9;
bool ST;
int Tid,T,n,K; vector<int> G[N];
int deep[N]={},fa[N]={},dfn[N]={},tdfn=0,sz[N]={},st[N][LogN]={},rt1,rt2,dia;
int hin[N]={},hout[N]={};
void getdia(int x,int fa) {
	for(auto y:G[x]) if(y!=fa)
		deep[y]=deep[x]+1,getdia(y,x);
	return ;
}
void setup(int x) {
	st[dfn[x]=++tdfn][0]=x,sz[x]=1,hin[x]=0;
	for(auto y:G[x]) if(y!=fa[x])
		fa[y]=x,deep[y]=deep[x]+1,setup(y),sz[x]+=sz[y],ckmax(hin[x],hin[y]+1);
	return ;
}
void setup2(int x) {
	int maxn=hout[x]+1,maxp=fa[x],secn=-inf;
	for(auto y:G[x]) if(y!=fa[x]) {
		if(hin[y]+1>maxn) secn=maxn,maxn=hin[y]+1,maxp=y;
		else ckmax(secn,hin[y]+1);
	}
	for(auto y:G[x]) if(y!=fa[x])
		hout[y]=(y==maxp?secn:maxn);
	for(auto y:G[x]) if(y!=fa[x]) setup2(y);
	return ;
}
int depmin(int x,int y) { return deep[x]<deep[y]?x:y; }
int lca(int x,int y) {
	if(x==y) return x;
	x=dfn[x],y=dfn[y];
	if(x>y) swap(x,y);
	int k=__lg(y-x);
	return fa[depmin(st[x+1][k],st[y-(1<<k)+1][k])];
}
int dist(int x,int y) { return deep[x]+deep[y]-2*deep[lca(x,y)]; }
namespace taskBF {
	int ufa[N]={};
	int father(int x) { return ufa[x]=ufa[x]==x?x:father(ufa[x]); }
	void link(int x,int y) { ufa[father(x)]=father(y); }
	bool same(int x,int y) { return father(x)==father(y); }
	void solve() {
		int ans=n,S,i,j,s,mx;
		for(S=1;S<(1<<n);++S) if(__builtin_popcount(S)==K) {
			for(i=1;i<=n;++i) ufa[i]=i;
			for(i=1;i<=n;++i) if(fa[i]&&(S>>(i-1)&1)&&(S>>(fa[i]-1)&1)) link(i,fa[i]);
			for(i=1,s=0;i<=n;++i) if((S>>(i-1)&1)&&ufa[i]==i) ++s;
			if(s>2) continue;
			for(i=1,mx=0;i<=n;++i) if(!(S>>(i-1)&1)) {
				for(j=1,s=n;j<=n;++j) if(S>>(j-1)&1)
					ckmin(s,dist(i,j));
				ckmax(mx,s);
			}
			ckmin(ans,mx);
		}
		printf("%d\n",ans);
		return ;
	}
}
namespace taskK2 {
	int X,cnt;
	int dfs(int x) {
		int minn=inf,maxn=-inf,u;
		for(auto y:G[x]) if(y!=fa[x]) {
			u=dfs(y)+1;
			ckmax(maxn,u);
			ckmin(minn,u);
		}
		if(minn>maxn) return 0;
		else {
			if(minn+maxn<0) return minn;
			else if(maxn==X) return ++cnt,-X-1;
			else return maxn;
		}
	}
	void solve() {
		int bl=1,br=n;
		while(bl<br) {
			X=(bl+br)>>1,cnt=0;
			int u=dfs(rt1);
			cnt+=u>=0;
			if(cnt<=K) br=X;
			else bl=X+1;
		}
		printf("%d\n",bl);
		return ;
	}
}
namespace taskA {
	void solve() {
		if(K>=dia-1) {
			printf("1\n");
			return ;
		}
		int bl=2,br=dia/2,X,cnt=0;
		while(bl<br) {
			X=(bl+br)>>1,cnt=0;
			if(X==dia-X) cnt=1;
			else {
				int dis=(dia-X)-X;
				cnt=2+max(0,dis-(2*(X-1)));
			}
			if(cnt<=K) br=X;
			else bl=X+1;
		}
		printf("%d\n",bl);
		return ;
	}
}
bool ED;
int main()
{
	usefile("hub");
	// cerr<<"Use memory: "<<((&ED)-(&ST))/1048576.0<<"MiB"<<endl;
	int i,j,x,y;
	read(Tid,T);
	for(int _=1;_<=T;++_) {
		read(n,K);
		for(i=1;i<=n;++i) G[i].clear();
		for(i=1;i<n;++i) read(x,y),G[x].push_back(y),G[y].push_back(x);
		if(n==K) { printf("0\n"); continue; }
		deep[1]=0,getdia(1,0),rt1=max_element(deep+1,deep+1+n)-deep;
		deep[rt1]=fa[rt1]=tdfn=0,setup(rt1),rt2=max_element(deep+1,deep+1+n)-deep;
		dia=deep[rt2];
		for(j=1;(1<<j)<=n;++j) for(i=1;i+(1<<j)-1<=n;++i)
			st[i][j]=depmin(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		hout[rt1]=-inf,setup2(rt1);
		if(n<=10) taskBF::solve(); else
		if(K<=2) taskK2::solve(); else
		if(Tid==13||Tid==14) taskA::solve();
		else printf("%d\n",(dia+4)/4);
	}
	// cerr<<"Use time: "<<(double)clock()/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
	return 0;
}