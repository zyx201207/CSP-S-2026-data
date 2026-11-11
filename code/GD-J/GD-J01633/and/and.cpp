#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int arr[200010],dp[100][200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int oa=1,ob=1;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		if((arr[i]+1)%2!=0) oa=0;
		if(arr[i]!=n-1) ob=0;
	}
	if(m==1)
	{
		int mx=-1;
		for(int i=1;i<=n;i++)
		{
			mx=max(mx,arr[i]);
		}
		cout << mx;
	} 
	else if(m==n)
	{
		sum=arr[1];
		for(int i=2;i<=n;i++)
		{
			sum=sum&arr[i];
		}
		cout << sum;
	}
	else if(m==2 && n<=2100)
	{
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				ans=max(ans,arr[i]&arr[j]);
			}
		}
		cout << ans;
	}
	else if(ob==1 && n%2==0)
	{
		cout << n-1;
	}
	else if(oa==1)
	{
		sort(arr+1,arr+1+n);
		cout << arr[n-m+1];
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			dp[1][i]=arr[i];
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=i;j<=n;j++)
			{
				for(int z=i-1;z<j;z++)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][z]&dp[1][j]);
				}
			}
		}
		cout << dp[m][n];
		
	}
	return 0;
}
