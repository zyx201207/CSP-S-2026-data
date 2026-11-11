#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long maxn=INT_MIN;
	for (long long i=1;i<=n;i++)
	{
		long long ans=0;
		long long sum=0;
		for (long long j=1;j<=n;j++)
		{
			sum+=abs(a[j]-a[i]);
			if (sum>m)
			{
				sum-=abs(a[j]-a[i]);
			}
			else if (sum==m)
			{
				ans++;
				break;
			}
			else
			{
				ans++;
			}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
