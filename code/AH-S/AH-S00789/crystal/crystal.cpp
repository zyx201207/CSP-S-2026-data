#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,ans,sum[500005];
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
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for (int i=1;i<=n;i++)
	{
		l=1,r=i-1;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			if (a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m)
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
