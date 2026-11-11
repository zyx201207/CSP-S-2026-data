#include<bits/stdc++.h>
using namespace std;
int c,T,n,ans;
long long d,x[2000001],dp[2000001];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
				dp[j]=1e10;
			dp[i]=0;
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j;k>=i;k--)
				{
					if(x[j]-x[k]<=d)
						dp[j]=min(dp[j],dp[k]+1);
					else
						break;
				}
			}
			for(int j=i+1;j<=n;j++)
			{
				int cnt=0;
				for(int k=j;k>=i;k--)
				{
					if(x[j]-x[k]<=d)
					{
						if(dp[k]+1==dp[j])
							cnt++;
					}	
					else
						break;
				}
				if(cnt==2)
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;	
}
/*
4 2
1 2 3 4

0 1 1 2

7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
