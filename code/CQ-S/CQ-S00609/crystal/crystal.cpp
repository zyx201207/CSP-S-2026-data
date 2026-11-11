/*
我忘却了所有悲剧，所见皆是奇迹。 
*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
/*
cirno /se /se
furina /se /se
yanami /se /se
yamada /se /se
sayaka /se /se
konata /se /se
蓝仙未未 /se /se 
*/
namespace Fast_io{
	#define IOSIZE 1000000
	char ibuf[IOSIZE],obuf[IOSIZE],*p1=ibuf,*p2=ibuf,*p3=obuf;
//	#ifndef Hazuki
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,IOSIZE,stdin),p1==p2)?EOF:*p1++)
	#define putchar(x) (p3==obuf+IOSIZE&&(fwrite(obuf,p3-obuf,1,stdout),p3=obuf),*p3++=x)
//	#endif
	struct Fast_IO{inline~Fast_IO(){fwrite(obuf,p3-obuf,1,stdout);}}Furina;
}using namespace Fast_io;
namespace TYX_YNXK{
	#define il inline
	#define vd void
	#define bl bool
	#define ll long long
	#define ull unsigned ll
	#define db double
	#define ldb long db
	#define pii pair<int,int>
	#define fi first
	#define se second
	#define MP make_pair
	#define pb push_back
	#define N 500005
	#define INF
	#define DEBUG cerr<<"\tfurina begin:\n"
	#define END cerr<<"\tyanami end.\n"
	#define c ch=getchar()
	il ll read(){
		ll x=0;bl w=1;char c;
		for(;ch<48||ch>57;c)if(ch=='-')w=0;
		for(;ch>47&&ch<58;c)x=(x<<3)+(x<<1)+(ch^48);
		return w?x:-x;
	}
	il vd write(ll x){
		if(x<0)putchar('-'),x=-x;
		static int st[21],top;top=0;
		do st[++top]=x%10,x/=10;while(x);
		while(top)putchar(st[top--]^48);
	}
	#undef c
	int n,ans,head,tail;ll m,a[N],q[N],tag,sum;
	signed main(){
		n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n),a[0]=a[1];
		head=1,tail=0;
		for(int i=1;i<=n;i++){
			tag+=a[i]-a[i-1];
			sum+=(a[i]-a[i-1])*(tail-head+1);
			while(sum>m){
				ll x=q[head++]+tag;
				sum-=x;
			}
			ans=max(ans,tail-head+2);
			q[++tail]=0-tag;
		}
		write(ans);
		return 0;
	}
}signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	TYX_YNXK::main();
	return 0;
}/*
y^2=ax^3+bx+c 椭圆曲线保佑
TL: 1.0s
ML: 1GB
*/
/*
事到如今还是会害怕吗。

经典读错题。只能做加法。
单调队列直接做。 

还假了一回。哈哈。
感觉今天要完。 
*/
