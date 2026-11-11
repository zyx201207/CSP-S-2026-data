#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[1010],dp[1010][1010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			dp[i][0]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				for(int k=1;k<i;k++)
				{
					if(abs(a[i]-a[k])<=d) dp[i][j]+=dp[k][j-1];
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(dp[i][j]>0&&dp[i][j]!=2) break;
				if(dp[i][j]>0&&dp[i][j]==2)
				{
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
