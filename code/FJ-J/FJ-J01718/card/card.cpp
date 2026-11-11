#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
long long n,m,a[521629],re[341899],l[341899],p;
//long long main+return 0
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(long long i=1;i<=n;++i){
		a[i]=read();
		l[a[i]]=i;
	}
//	for(long long i=1;i<=m;++i)printf("l[%lld]=%lld\n",i,l[i]);
	for(long long i=n;i;--i){
		p=i;
		while(p!=n+1){
			p=l[a[p]];
			++re[a[p]],++p;
		}
	}for(long long i=1;i<=m;++i)printf("%lld ",re[i]);
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
