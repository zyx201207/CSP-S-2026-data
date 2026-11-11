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
const int N=500099;
int n; ll m,a[N]={},pre[N]={};
ll cost(int l,int r) {
	return a[r]*(r-l+1)-(pre[r]-pre[l-1]);
}
int main()
{
	usefile("crystal");
	int i,j,ans=0;
	read(n,m);
	for(i=1;i<=n;++i) read(a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
	for(i=1,j=1;i<=n;++i) {
		while(cost(j,i)>m) ++j;
		ckmax(ans,i-j+1);
	}
	printf("%d\n",ans);
	return 0;
}