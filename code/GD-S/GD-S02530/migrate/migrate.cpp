#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
long long dp[2000005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		memset(dp,0,sizeof(dp));
		dp[2*d]=1;
		for(int i=2*d+1;i<=n;i++)
		{
			dp[i]=dp[i-1]*d;
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
