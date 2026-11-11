#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}struct{long long le,l;char c;}a[291699],b[291699];
long long n,c[291699],l,L1=0,L2=0,l1,l2,re;
//long long main+return 0
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(long long i=1;i<=n;++i){
		a[i].l=l;
		a[i].le=read(),cin>>a[i].c;
		l+=a[i].le;
	}l=0;
	for(long long i=n;i;--i){
		b[n-i+1].le=a[i].le;
		b[n-i+1].c=a[i].c;
		b[n-i+1].l=l;
		l+=b[n-i+1].le;
	}l>>=1;
//	printf("l=%lld\n",l);
//	for(long long i=1;i<=n;++i){
//		printf("%lld %c\n",b[i].le,b[i].c);
//	}printf("\n");
	while(1){
		
		while(l1<=l2){
			l1+=a[++L1].le;
			if(a[L1].c!=b[L2].c&&L1*L2)re+=min(a[L1].le,l2-a[L1].l);
//			printf("l1=%lld l2=%lld\n",l1,l2);
			if(l1>=l&&l2>=l)break;
		}if(l1>=l&&l2>=l)break;
		while(l1>l2){
			l2+=b[++L2].le;
			if(a[L1].c!=b[L2].c&&L1*L2)re+=min(b[L2].le,l1-b[L2].l);
//			printf("l1=%lld l2=%lld\n",l1,l2);
			if(l1>=l&&l2>=l)break;
		}if(l1>=l&&l2>=l)break;
	}printf("%lld\n",re);
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
1 a
1 b
5 c
*/
