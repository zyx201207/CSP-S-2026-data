#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}long long n,m,a[291699],b[291699],f,r,c=1,ok;
//long long main+return 0
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(long long i=1;i<=n;++i){
		a[i]=read();
	}sort(a+1,a+n+1,greater<long long>());
//	for(long long i=1;i<=n;++i){
//		printf("%lld ",a[i]);
//	}printf("\n");
	for(long long i=30;~i;--i){
		f=0;
		for(long long j=1;j<=n;++j){
			if(a[j]&(1<<i)){
//				printf("a[%lld] have %lld\n",j,i);
				if(!f){
					f=1;
					b[c]=a[j];
				}else{
					b[++c]=a[j],--i;
				}
			}if(c==m){ok=1;break;}
		}if(ok)break;
	}r=b[1];
	for(long long i=2;i<=m;++i)r&=b[i];
	printf("%lld",r);
}
//a&b=((a+b)-(a^b))>>1
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
