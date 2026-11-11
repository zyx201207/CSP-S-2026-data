#include<bits/stdc++.h>
using namespace std;
const long long N=2000010;
long long c,t,n,d,x[N];
pair<long long,long long>dp[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c<=10)
		{
			long long ans=0;
			for(long long i=1;i<=n;i++)
			{
				for(long long j=1;j<=n;j++)
				{
					dp[j]={0,INT_MAX};
				}
				dp[i]={1,0};
				for(long long j=i+1;j<=n;j++)
				{
					for(long long k=j-1;k>=i;k--)
					{
						if(x[j]-x[k]<=d)
						{
							if(dp[k].second<dp[j].second-1)
							{
								dp[j]={dp[k].first,dp[k].second+1};
							}
							else if(dp[k].second==dp[j].second-1)
							{
								dp[j].first+=dp[k].first;
							}
						}
					}
//					if(dp[j].first==2)
//					{
//						cout<<i<<' '<<
//					}
					ans+=(dp[j].first==2);
				}
			}
			cout<<ans<<'\n';
		}
		else if(c==11||c==12)
		{
			long long tg=d/(x[2]-x[1]);
			if(tg<=1)
			{
				cout<<"0\n";
			}
			else
			{
				cout<<max(0ll,n+1-2*tg)<<'\n';
			}
		}
	}
	return 0;
}
