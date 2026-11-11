#include<bits/stdc++.h>
using namespace std;
long long dp[200005];
long long a[200005];
int b[200005];
long long ma;
int n,m;
bool v[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool flag=1;
	long long ma=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		if(a[i]!=4) flag=0;	
		b[i]=1;
	} 
	if(flag)
	{
		cout<<4;
		return 0;
	}
	if(m==1)
	{
		cout<<ma;
		return 0;
	}
	long long mx=0;
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n-1)
	{
			long long sum=a[1];
			for(int i=2;i<n;i++)
			{
				sum&=a[i];
			}
			ma=max(sum,ma);
			long long su=a[1];
			for(int i=3;i<=n;i++)
			{
				su&=a[i];
			}
			ma=max(su,ma);
			long long sm=a[2];
			for(int i=3;i<=n;i++)
			{
				sm&=a[i];
			}
			ma=max(sm,ma);
			cout<<ma;
			return 0;
		}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		int cnt=1;
		v[a[i]]=1;
		for(int j=m;j>=b[i];j--)
		{
			if(cnt<m) 
			{
				if(!v[a[i]])
				{
					dp[j]=max(dp[j],dp[j-1]&a[i]);
					
				} 
				cnt++;
			}
			else
			{
				dp[j]=dp[j-1];
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=200005;i++)
	{
		ans=max(dp[i],ans);
	}
	cout<<ans;
	return 0;
 }

