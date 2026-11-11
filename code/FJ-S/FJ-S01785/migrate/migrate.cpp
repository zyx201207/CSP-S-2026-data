#include<bits/stdc++.h>

//#define int long long

using namespace std;

const int N=2e6+5,M=5e3+5;

int c,T=1,n,d,ans;

int x[N],dp[M][M],pr[N];

void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		pr[i]=i;
		for(int j=i-1;j>=1;j--)
		{
			if(x[i]-x[j]<=d) pr[i]=j;
			else break;
		}
//		cout<<pr[i]<<' ';
	}
//	cout<<'\n';
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++) for(int k=0;k<=n;k++) dp[j][k]=0;
		dp[i][0]=1;
		for(int j=i+1;j<=n;j++)
		{
			int l=max(i,pr[j]);
			for(int k=l;k<j;k++)
			{
				for(int o=0;o<=j-i+1;o++)
				{
					dp[j][o+1]+=dp[k][o];
				}
				
			}
			for(int k=1;k<=j-i+1;k++)
			{
				if(dp[j][k])
				{
					if(dp[j][k]==2) 
					{
						ans++;
//						cout<<i<<' '<<j<<'\n';
					}
					break;
				}
				
			}
			
		}
		
	}
	cout<<ans<<'\n';
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

