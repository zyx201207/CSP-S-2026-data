#include <bits/stdc++.h>
using namespace std;
long long x[2000007];
int dp[5007][5007];
int sum[5007][5007];
int s[5007][5007];
int pre[2000007];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long d;
		cin>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				s[i][j]=1e7;
				dp[i][j]=0;
				sum[i][j]=0;
			}
			s[i][i]=0;
		}
		int p=1;
		pre[1]=1;
		for(int i=2;i<=n;i++)
		{
			while(x[i]-x[p]>d) p++;
			pre[i]=p;
		}
		for(int i=1;i<n;i++)
		{
			int last=i;
			if(x[i+1]-x[i]<=d)
			{
				s[i][i+1]=1;
				for(int j=i+2;j<=n;j++)
				{
					if(x[j]-x[last]>d)
					{
						if(x[j]-x[j-1]>d) break;
						s[i][j]=s[i][j-1]+1,last=j-1;
					}else s[i][j]=s[i][j-1];
				}
			}
		}
		for(int len=2;len<=n;len++)
		{
			for(int i=1;i+len-1<=n;i++)
			{
				int j=i+len-1;
				if(x[j]-x[i]<=d) dp[i][j]=1;
				else{
					int lbound=lower_bound(s[i]+pre[j],s[i]+j,s[i][j]-1)-s[i];
					int rbound=upper_bound(s[i]+pre[j],s[i]+j,s[i][j]-1)-s[i];
					dp[i][j]+=sum[i][rbound-1]-sum[i][lbound-1];
				}
				sum[i][j]=sum[i][j-1]+dp[i][j];
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(dp[i][j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
