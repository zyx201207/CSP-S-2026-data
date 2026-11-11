#include<bits/stdc++.h> 
using namespace std;
long long ans=0,n,m,c,t,d,dp[500100];
struct cn
{
	int x,y,z;
};
int main()
{ 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	while(t--)
	{
		cin>>n>>d;
		long long x[500100],ans=0;
		memset(dp,1e9+7,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			for(int j=i-1;j>=1;j--)
			{
				if(x[i]-x[j]>=d)break;
				ans++;
			}
		}
	
		cout<<n-ans<<endl;
	}
	return 0;
}
