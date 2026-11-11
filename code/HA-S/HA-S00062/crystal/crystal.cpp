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
constexpr int N=5e5+30;
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
int n,m;
int a[N];
void solve(){
	n=rd(),m=rd();
	rep(i,1,n)a[i]=rd();
	sort(a+1,a+n+1);
	int l=1,cur=0,ans=0;
	rep(r,1,n){
		int c=a[r]-a[r-1];
		cur+=c*(r-l);
		while(cur>m){
			cur-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	print(ans);
}
bool _ed;
signed main(){
	#ifndef NATSU
	file("crystal");
	#endif
	#ifdef SAYHERE
	st=clock();
	#endif
	int tt=1;
	while(tt--)solve();
	#ifdef SAYHERE
	cerr<<"\nTime:"<<clock()-st<<"ms";
	cerr<<"\nMemory:"<<(&_ed-&_st)/1048576.0<<"MB";
	#endif
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
