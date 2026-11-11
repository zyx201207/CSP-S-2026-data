#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[0]=a[i];
		for(int j=m;j>=1;j--)
		{
			for(int k=1;k<=n;k++)
			{
				if(k!=i)
				{
					dp[j]=max(dp[j],dp[j-1]&a[k]);
				}
			}
		}
	}
	cout<<dp[m];
	return 0;
} 
