#include<cstdio>
#include<algorithm>
#include <iostream>
using namespace std;
#define f(x,y,z) for(int x=y;x<=z;x++)
#define g(x,y,z) for(int x=y;x>=z;x--)
#define int long long
#define N 500005
int m,a[N],s[N];int n;
inline int read(){
	int a=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	f(i,1,n)a[i]=read();
	sort(a+1,a+1+n);
	f(i,1,n)s[i]=s[i-1]+a[i];
	int ans=1;
	f(i,1,n){
		int l=1,r=i,k=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(mid*1ll*a[i]-(s[i]-s[i-mid])<=m)
				l=mid+1,k=mid;
			else r=mid-1;
		}
		ans=max(ans,k);
	}
	printf("%lld\n",ans);
	return 0;
}