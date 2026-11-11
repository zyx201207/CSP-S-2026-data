#include<bits/stdc++.h>
using namespace std;
long long dp[5005][5005],n,m,b[5],ma,a[200005],an[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	
	sort(a+1,a+n+1);
	if(ma<4)
	{
		for(int i=1;i<=n;i++)
		{
			b[a[i]]++;
		}
		if(b[3]>=m)
		{
			cout<<3;
		}
		else if(b[3]+b[2]>=m)
		{
			cout<<2;
		}
		else if(b[3]+b[1]>=m)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i][1]=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=m;j++)
			{
				dp[i][j]=dp[i-1][j];
				dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i][j]);
			}
		}
		cout<<dp[n][m];
	}
	else
	{
		int f=0,ff=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=i-1) f=1;
			if(pow(2,log2(a[i]+1))!=a[i]+1) ff=1;
		}
		if(ff==0)//A
		{
			cout<<a[n-m+1];
		}
		else if(f==0)//B
		{
			int t=0;
			while(pow(2,t)-1<=n-1)
			{
				t++;
			}
			t--;
			int u=pow(2,t)-1;
			dp[n][m]=u;
			for(int i=u-1;i>=u-m+1;i--)
			{
				dp[n][m]=dp[n][m]&i;
			}
			cout<<dp[n][m];
		}
		else
		{
			cout<<0;
		}
	}
}
//Trick||Treat!
