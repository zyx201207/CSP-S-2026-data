#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
ll c,t,dp[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(dp,0,sizeof dp);
		ll n,d,x[maxn];
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		dp[1]=1;
		ll id=1,cnt=1;
		while(true)
		{
			for(int i=1;i<=n;i++)
			{
				if(x[i]<=id+d) dp[i]=cnt;
				else
				{
					id=i-1;
					cnt++;
					dp[i]=cnt;
				}
			}
		}
		
	}
	return 0;
} 
