#include<bits/stdc++.h>
#define inf 10000
using namespace std;
long long c,t,n,d,x[2000010],ans;
long long dis,dd;
long long l,r,lb,rb,dp[5010],mn[5010],flag;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(1<=c && c<=10)
	{
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)dp[j]=0,mn[j]=inf;
			dp[i]=1;mn[i]=0;
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[j-1]>d)break;
				for(int k=j-1;k>=i && x[j]-x[k]<=d;k--)
				{
					if(mn[k]+1<mn[j])
						dp[j]=dp[k],mn[j]=mn[k]+1;
					else
						dp[j]+=dp[k];
				}
				if(dp[j]==2)++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
	}
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		dis=x[2]-x[1];
		if(d<dis*2)
		{
			cout<<"0\n";
			continue;
		}
		dd=(d+1)/dis;
		cout<<max(n-dd*2+1,0ll)<<'\n';
	}
	return 0;
}
