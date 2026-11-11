#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
long long bsearch(long long x)
{
	long long l=1,r=x;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if((x-mid)*a[x]-(b[x-1]-b[mid-1])<=m)
			r=mid-1;
		else
			l=mid+1;
	}
	return x-(r+1)+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	long long ans=0;
	for(int i=n;i>=1;i--)
		ans=max(ans,bsearch(i));
	printf("%lld",ans);
	return 0;
}
