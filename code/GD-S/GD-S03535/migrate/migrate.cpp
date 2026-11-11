#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[1000005],dp[10000005],x,ans=0,x1[1000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int t1=1;t1<=t;t1++)
	{
		ans=0;
		int z=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=2;i<=n;i++)
		{
			if(a[i]<=d+1)dp[i]=1;
			else{
				x=i;
				break;
			}
		}
		for(int i=x;i<=n;i++)
		{
			dp[i]=dp[i-d]+1;
		}
		long long xyz=1;
		for(int i=d+1;i<=n;i++)
		{
			for(int k=i-d+1;k<i;k++)
			{
				if(dp[k]==dp[k-1])
				{
					xyz++;
				}
			}
			if(xyz==2){
				ans++;
				x1[z]=i;
				z++;
			}
				xyz=1;
		}
		cout<<ans<<endl;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
	}
}
