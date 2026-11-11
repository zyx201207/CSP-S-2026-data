#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int c,t,n,dp[N][N],maxmin; 
int a[N];
int ksm(int r,int s)
{
	int res=1;
	for(int i=1;i<=s;i++)
	{
		res=res*((r-i+1)/i);
	}
	return res;
}

void solve()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<0)maxmin=max(maxmin,-a[i]);
	}
	if(maxmin>0)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=a[i]+maxmin;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=c)dp[i][j]=1;
			else
			{
				int p=(a[j]-a[i])/c;
				int sum=ksm((j-i-1),p);
				dp[i][j]=sum;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(dp[i][j]==2)
			{
				cnt++;
			}
		}
	}
	cout<<cnt<<'\n';
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
}
