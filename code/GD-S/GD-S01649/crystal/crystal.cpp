#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long q[500010];
long long check(long long b,long long e)
{
	long long sum=(e-b+1)*a[e]-(q[e]-q[b-1]);
	return sum<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		q[i]=q[i-1]+a[i];
	}
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		long long l=1,r=i;
		while(l<=r)
		{
			long long mid=(l+r+1)/2;
			if(check(mid,i)==1)
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
