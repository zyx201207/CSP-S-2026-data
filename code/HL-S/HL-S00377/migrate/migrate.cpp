#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	vector<ll>a(2000010),dp(2000010,0),sum(2000010,0),re(2000010,0);
	ll c,t,n,d;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		for(int y=0;y<n-3;y++)
		{
			dp=re;
			ll t1=0;
			for(int j=y;j<n;j++)
			{
				if(a[j]-a[y]>d)
				{
					t1=j;
					break;
				}
				dp[j]=1;
			}
			for(int j=t1;j<n;j++)
			{
				for(int k=j-1;k>0;k--)
				{
					if(a[j]-a[k]>d)
					{
						break;
					}
					dp[j]++;
				}
			}
			for(int j=0;j<n;j++)
			{
				if(dp[j]==2)
				{
					sum[i]++;
				}
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<sum[i]<<endl;
	}
	return 0;
}
