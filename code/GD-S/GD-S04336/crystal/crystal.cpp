#include<bits/stdc++.h>
using namespace std;
long long a[500100],diff[500100];
long long n,m;
long long ned(long long x,long long y)
{
	return a[y]*(y-x+1)-(diff[y]-diff[x-1]);
}
bool check(long long x,long long now)
{
	if(ned(now,x)>m) return 0;
	else return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++) diff[i]=diff[i-1]+a[i];
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		long long l=i,r=n;
//		printf("%d---------\n",i);
		while(l<r)
		{
			long long mid=(l+r+1)>>1;
//			printf("%d %d %d %d\n",l,r,mid,ned(i,mid));
			if(check(mid,i)) l=mid;
			else r=mid-1;
		}
		ans=max(ans,l-i+1);
	}
	printf("%lld",ans);
	return 0;
}
