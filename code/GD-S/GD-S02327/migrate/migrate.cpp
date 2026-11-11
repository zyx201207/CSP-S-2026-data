#include<bits/stdc++.h>
#define int long long
using namespace std;
int asdf,T;
int n,m;
int a[2000005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>asdf>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(1<=asdf&&asdf<=6)
		{
			int dp[305][305]={0},s[305][305]={0};
			memset(dp,0x3f,sizeof(dp));
			for(int i=1;i<=n;i++)
			{
				s[i][i]=1;
				dp[i][i]=0;
				for(int j=i+1;j<=n;j++)
				{
					for(int k=j-1;k>=i;k--)
					{
						if(abs(a[j]-a[k])>m) break;
						if(dp[i][k]+1<dp[i][j])
						{
							s[i][j]=s[i][k];
							dp[i][j]=dp[i][k]+1;
						}
						else if(dp[i][k]+1==dp[i][j])
						{
							s[i][j]+=s[i][k];
						}
					}
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(s[i][j]==2) cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
		else if(asdf>=11&&asdf<=12)
		{
			int d=a[2]-a[1];
			m/=d;
			if(m<=1)
			{
				cout<<0<<"\n";
				continue;
			}
			cout<<max(n-m*2+1,0ll)<<"\n";
		}
	}
	return 0;
}
