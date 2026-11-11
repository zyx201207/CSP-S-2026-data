#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long qz[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		qz[i]=qz[i-1]+a[i];
	}
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		long long l=1,r=i,zh=1;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			long long qd=i-mid+1;
			long long sum=qz[i]-qz[qd-1];
			if (a[i]*mid-sum<=m)
			{
				l=mid+1;
				zh=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		ans=max(ans,zh);
	}
	cout<<ans<<endl;
} 
