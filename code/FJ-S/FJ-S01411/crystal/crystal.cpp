#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
long long n,m,a[521629],s[521629],l,r,mi,re;
bool ch(long long x){
	for(long long lp=1;lp+x-1<=n;++lp){
		long long rp=lp+x-1;
		long long t=a[rp]*(rp-lp+1)-(s[rp]-s[lp-1]);
		if(t<=m)return 1;
	}return 0;
}signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(long long i=1;i<=n;++i){
		a[i]=read();
	}sort(a+1,a+n+1);
	for(long long i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	l=1,r=n;
	while(l<=r){
		mi=l+(r-l>>1);
		if(ch(mi))l=mi+1,re=mi;
		else r=mi-1;
	}printf("%lld",re);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 3
1 2 4 4 4
*/
