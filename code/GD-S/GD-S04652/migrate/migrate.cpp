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
const int N=2000099;
bool ST;
int Tid,T,n; ll a[N]={},D,ans;
int tor[N]={},tol[N]={},sl[N]={},sr[N]={},cl[N]={},cr[N]={};
pair<int,int> asl[N],asr[N];
ll calc(int lx,int rx,int ly,int ry) {
	if(lx>rx||ly>ry) return 0;
	else return (ll)(rx-lx+1)*(ry-ly+1);
}
bool ED;
int main()
{
	usefile("migrate");
	// cerr<<"Use memory: "<<((&ED)-(&ST))/1048576.0<<"MiB"<<endl;
	int i,j,x;
	read(Tid,T);
	for(int _=1;_<=T;++_) {
		read(n,D),ans=0;
		for(i=1;i<=n;++i) read(a[i]);
		for(i=1,j=1;i<=n;++i) {
			ckmax(j,i);
			while(j<n&&a[j+1]-a[i]<=D) ++j;
			tor[i]=j;
		}
		for(i=n,j=n;i;--i) {
			ckmin(j,i);
			while(j>1&&a[i]-a[j-1]<=D) --j;
			tol[i]=j;
		}
		for(i=1;i<=n;++i) asl[i]=asr[i]=make_pair(n+1,0);
		for(i=1;i<=n;++i) asl[tol[i]].second=i,asr[tor[i]].second=i;
		for(i=n;i;--i) asl[tol[i]].first=i,asr[tor[i]].first=i;
		memset(sl,0,(n+2)<<2),memset(sr,0,(n+2)<<2);
		memset(cl,0,(n+2)<<2),memset(cr,0,(n+2)<<2);
		for(i=1;i<=n;++i) {
			if(tol[i]<i&&tor[tol[i]]==i) {
				sl[i]=sl[tol[i]];
				cl[i]=cl[tol[i]]+max(0,asr[i].second-tol[i]+1);
			} else sl[i]=i,cl[i]=0;
		}
		for(i=n;i;--i) {
			if(tor[i]>i&&tol[tor[i]]==i) {
				sr[i]=sr[tor[i]];
				cr[i]=cr[tor[i]]+max(0,tor[i]-asl[i].first+1);
			} else sr[i]=i,cr[i]=0;
		}
		for(i=1;i<=n;++i) {
			x=tor[i],j=tor[x];
			if(i<x&&x<j&&i<tol[j]&&tol[j]+1==x) {
				ans+=cr[j];
				if(tol[tol[j]]==i)
					ans+=(ll)cl[i]*cr[j];
			}
		}
		for(i=n;i;--i) {
			x=tol[i],j=tol[x];
			if(j<x&&x<i&&x+1==tor[j]&&tor[j]<i)
				ans+=cl[j];
		}
		// for(i=1;i<=n;++i) for(j=i+1;j<=n;++j)
		// 	ans+=i<tol[j]&&tol[j]+1==tor[i]&&tor[i]<j;
		for(i=1;i<n;++i)
			if(asl[i].first<=asl[i].second&&asr[i+1].first<=asr[i+1].second)
				ans+=calc(asr[i+1].first,min(asr[i+1].second,i-1),max(asl[i].first,i+2),asl[i].second);
		printf("%lld\n",ans);
	}
	// cerr<<"Use time: "<<(double)clock()/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
	return 0;
}