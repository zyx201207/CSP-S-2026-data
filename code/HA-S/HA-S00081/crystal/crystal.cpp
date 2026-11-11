#include<bits/stdc++.h>
using namespace std;
int k,l,mid,n,r;
long long a[500001],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		l=1,r=i-1;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(a[i]*(long long)(i-mid)-a[i-1]+a[mid-1]<=m)r=mid;
			else l=mid+1;
		}
		if(k<i-r+1)k=i-r+1;
		a[i]+=a[i-1];
	}
	printf("%d",k);
	return 0;
}
