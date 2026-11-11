#include <bits/stdc++.h>
using namespace std;
long long a[500010],dp[500010],dp2[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,c=0;
	int flag=0,flag2=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		long long x=c;
		c=abs(a[i]-a[i-1]);
		if(a[i]!=i) flag=1;
		if(c!=x) flag2=1;
	}
	if(flag==0)
	{
		long long ans=1;
		dp[1]=0;
		for(long long i=2;i<=n;i++)
		{
			dp[i]=dp[i-1]+i-1;
			if(dp[i]<=m) ans++;
		}
		cout<<ans;
		return 0;
	}
	else if(flag2==0)
	{
		long long ans=1;
		dp[1]=0;
		for(long long i=2;i<=n;i++)
		{
			dp2[i]=abs(a[i-1])+dp2[i-1];
			if(dp[i]<=m) ans++;
		}cout<<ans;
		return 0;
	}
	else{
		sort(a+1,a+1+n); 
		long long cha=0,ans=0;
		for(long long i=1;i<=n;i++)
		{
			cha=0;
			for(long long j=1;j<=i;j++)
			{
				cha+=abs(a[i]-a[j]);
			}
			if(cha<=m) ans++;
			else break;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

