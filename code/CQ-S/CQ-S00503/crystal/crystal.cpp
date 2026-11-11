#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum[500005];
bool check(int x)
{
	for (int i=x;i<=n;i++)
	{
		if (sum[i]-sum[i-x]+m>=a[i]*x)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l=0,r=n,ans=0;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid))
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
/*
5 8
-3 -1 2 2 7


*/
