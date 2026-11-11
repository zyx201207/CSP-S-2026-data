#include<iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	long long a[n+5];
	bool b[n+5]={0}; 
	long long dp[m+1]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(dp[1]<a[i])
		{
			dp[1]=a[i];
			b[i]=1;
		}
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[j]==0)
			{
				if((dp[i-1]&a[j])>dp[i])
				{
					dp[i]=(dp[i-1]&a[j]);
					b[j]=1;
				}
			}
		}
	}
	cout<<dp[m];
	return 0;
}
