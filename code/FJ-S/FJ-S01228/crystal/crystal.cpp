#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long s[500005];
bool check(int mid)
{
	for(int i=mid;i<=n;i++)
	{
		long long cost=a[i]*mid-(s[i]-s[i-mid]);
		if(cost<=m)
		{
			return 1;
		}
	}
	return 0;
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
		s[i]=s[i-1]+a[i];
	}
	int l=1;
	int r=n;
	int ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
