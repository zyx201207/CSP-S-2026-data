#include<iostream>
#include<algorithm>
#include<ctime>
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define rep(i,s,t) for(int i=(s),lim=(t)+1;i!=lim;++i)
#define dep(i,s,t) for(int i=(s),lim=(t)-1;i!=lim;--i)
#define int long long
using namespace std;
bool _st;
time_t st;
constexpr int N=2e6+50,llinf=2e18;
template<typename T=int>T rd(){
	T x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())f=c==45?-1:f;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return  x*f; 
}
template<typename T>void print(T x){
	static long obuf[23],top0=0;
	if(x<0)putchar(45),x=-x;
	do obuf[top0++]=x%10,x/=10;while(x);
	while(top0)putchar(obuf[--top0]+48);
}
int sub,tt;
int n,k;
int a[N];
namespace sp1{
	constexpr int C=5e3+30;
	int f[C],cnt[C];
	int pre[C];
	void dfs(int x){
		if(f[x]!=-1)return;
		rep(prv,pre[x],x-1){
			dfs(prv);
			if(f[prv]+1<f[x]||f[x]==-1){
				f[x]=f[prv]+1,cnt[x]=cnt[prv];
			}
			else if(f[prv]+1==f[x]){
				cnt[x]+=cnt[prv];
			}
		}
	}
	void solve(){
		n=rd(),k=rd();
		rep(i,1,n){
			a[i]=rd();
			if(i==1)pre[i]=1;
			else pre[i]=lower_bound(a+1,a+i+1,a[i]-k)-a;
		}
		int ans=0;
		rep(s,1,n-1){
			rep(i,0,n)cnt[i]=0;
			rep(i,0,s-1)f[i]=llinf;
			f[s]=0,cnt[s]=1;
			rep(i,s+1,n)f[i]=-1;
			dep(i,n,s)if(f[i]==-1)dfs(i);
			rep(t,s+1,n){
				if(cnt[t]==2)ans++;
			}
//			rep(i,1,n)print(f[i]),putchar(' ');
//			putchar('\n');
		}
		print(ans),putchar(10);
	}
}
namespace spA{
	int sum[N],ls[N],rs[N],tn=0,c,R;
	void init(){
		fill(sum,sum+tn+1,0);
		fill(ls,ls+tn+1,0);
		fill(rs,rs+tn+1,0);
		tn=0,R=0;
	}
	void update(int&u,int l,int r,int p,int c){
		if(!u)u=++tn;
		if(l==r)return sum[u]+=c,void();
		int mid=(l+r)>>1;
		if(p<=mid)update(ls[u],l,mid,p,c);
		else update(rs[u],mid+1,r,p,c);
		sum[u]=sum[ls[u]]+sum[rs[u]];
	}
	int query(int u,int l,int r,int ql,int qr){
		if(!u)return 0;
		if(ql<=l&&r<=qr)return sum[u];
		int mid=(l+r)>>1,ret=0;
		if(ql<=mid)ret=query(ls[u],l,mid,ql,qr);
		if(qr>=mid)ret+=query(rs[u],mid+1,r,ql,qr);
		return ret;
	}
	void solve(){
		init();
		n=rd(),k=rd();
		rep(i,1,n){
			a[i]=rd();
		}
		c=a[2]-a[1];
//		int ans=0;
		dep(i,n,1){
//			int cres=(a[i]%c+c)%c;
		}
	}
}
void solve(){
	if(sub<=10)sp1::solve();
	if(11<=sub&&sub<=12)spA::solve();
}
bool _ed;
signed main(){
	#ifndef NATSU
	file("migrate");
	#endif
	#ifdef SAYHERE
	st=clock();
	#endif
	sub=rd(),tt=rd();
	while(tt--)solve();
	#ifdef SAYHERE
	cerr<<"\nTime:"<<clock()-st<<"ms";
	cerr<<"\nMemory:"<<(&_ed-&_st)/1048576.0<<"MB";
	#endif
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
