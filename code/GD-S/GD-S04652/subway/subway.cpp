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
const int N=529,M=500099; const ll inf=2e18;
bool ST;
int Tid,n,m,D,q,a[M]={},t[M]={}; ll w[M]={},f[N][N]={}; vector<pair<int,int>> bel[M];
bool ED;
int main()
{
	usefile("subway");
	int i,j,k,x,y; ll ans;
	// cerr<<"Use memory: "<<((&ED)-(&ST))/1048576.0<<"MiB"<<endl;
	read(Tid,n,m,D,q);
	for(i=1;i<=m;++i) read(w[i]);
	for(i=1;i<=n;++i) {
		int len;
		read(len);
		for(j=1;j<=len;++j) read(a[j],t[j]);
		for(j=1;j<=len;++j) bel[a[j]].push_back({i,t[j]});
	}
	for(i=1;i<=n;++i) for(j=1;j<=n;++j) f[i][j]=i==j?0:inf;
	for(i=1;i<=m;++i) {
		for(j=0;j<int(bel[i].size());++j)
			for(k=0;k<int(bel[i].size());++k)
				ckmin(f[bel[i][j].first][bel[i][k].first],ll(bel[i][j].second+bel[i][k].second));
	}
	for(k=1;k<=n;++k) for(i=1;i<=n;++i) for(j=1;j<=n;++j)
		ckmin(f[i][j],f[i][k]+f[k][j]);
	for(i=1;i<=q;++i) {
		read(x,y);
		ans=inf;
		for(j=0;j<int(bel[x].size());++j)
			for(k=0;k<int(bel[y].size());++k)
				ckmin(ans,bel[x][j].second+bel[y][k].second+f[bel[x][j].first][bel[y][k].first]);
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	// cerr<<"Use time: "<<(double)clock()/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
	return 0;
}