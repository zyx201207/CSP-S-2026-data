#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=1,x,a[500005],s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(long long i=2;i<=n;i++)
	{
		long long l=1,r=i;
		while(l<r)
		{
			long long mid=(l+r)/2;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		mx=max(mx,i-l+1);
	}
	cout<<mx;
	return 0;
}
