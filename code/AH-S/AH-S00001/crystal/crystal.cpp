#include <bits/stdc++.h>
using namespace std;
const int N = 500000+5;
int n;
long long m;
long long dp[5005][5005];
long long a[N];
long long minn=0x3f3f3f3f;
long long ans=0;
int search(long long l,long long r)
{
	if(r-l==1)return l;
	long long mid=(l+r)/2;
	long long d=0;
	for(long long i=1;i<=n;i++)
	{
		if(a[i]<mid)d+=mid-a[i];
		else break;
		if(d>m)break;
	}
	if(d>m)search(l,mid);
	if(d<m)search(mid,r);
	if(d==m)return mid;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=5000)
	{
		for(int i=1;i<n;i++)
		{
			dp[i][i+1]=a[i+1]-a[i];
			if(dp[i][i+1]<minn)minn=dp[i][i+1];
		}
		if(minn>m)return cout<<1,0;
		for(int len=3;len<=n;len++)
		{
			minn=0x3f3f3f3f;
			for(int l=1;l+len<=n;l++)
			{
				int r=l+len-1;
				dp[l][r]=dp[l][r-1]+(r-l)*dp[r-1][r];
				if(dp[l][r]<minn)minn=dp[l][r];
			}
			if(minn>m)return cout<<len-1,0;
		}
	}
	else
	{
		sort(a+1,a+1+n);
		long long standard=search(a[1],a[n]);
		for(long long i=n;i>=1;i--)
	    {
			if(a[i]<=standard)
			{
				ans=i;
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
