#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000100],b[1000100];
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	long long s=1;
	for(long long i=1;i<=n;i++)
	{
		long long x=i-1;
		for(long long j=20;j>=0;j--)
			if(x-(1<<j)>=0)
			{
				long long y=x-(1<<j),s=b[i]-b[y];
				if(((i-y)*a[i]-s)<=m)
					x=y;
			} 
		s=max(s,i-x);
	}
	printf("%lld\n",s);
}
