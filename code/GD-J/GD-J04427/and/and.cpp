#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int f[2005][2005];
int s[10];
int d[(1ll<<19)];
int dp[(1ll<<19)];
int n,m,maxx;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		int sum=(1ll<<30)-1;
		for(int i=1;i<=n;i++) sum=sum&a[i];
		cout<<sum;
		return 0;
	}
	if(n<=2000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
			}
			f[i][1]=max(f[i][1],a[i]);
		}
		cout<<f[n][m];
		return 0;
	}
	if(a[n]<=4)
	{
		for(int i=1;i<=n;i++)
		{
			s[a[i]]++;
		}
		if(s[4]>=m)
		{
			cout<<4;
			return 0;
		}
		if(s[3]>=m)
		{
			cout<<3;
			return 0;
		}
		if(s[3]+s[2]>=m)
		{
			cout<<2;
			return 0;
		}
		if(s[3]+s[1]>=m)
		{
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		while(t)
		{
			if(t%2==0) f=0;
			t/=2;
		}
	}
	if(f==1)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
		for(int i=1;i<=n;i++) dp[a[i]]++;
		for(int i=a[n];i>=0;i--)
		{
			for(int j=1;j<=18;j++)
			{
				if(((i>>j)&1)==0)
				{
					dp[i]+=dp[i^(1ll<<j)];
				}
			}
		}
		for(int i=a[n];i>=0;i--)
		{
			if(dp[i]>=m)
			{
				cout<<i;
				return 0;
			}
		}
		cout<<0;
}
