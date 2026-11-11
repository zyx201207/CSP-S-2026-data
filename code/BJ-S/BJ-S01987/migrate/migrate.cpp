#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=305,inf=1e9+7;
ll a[N],dp[N][N];
int stp[N][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	ll ans;
	ll d;
	cin>>c>>t;
	if(c<=10)
	{
		while(t--)
		{
			ans=0;
			memset(dp,0,sizeof(dp));
			memset(stp,0,sizeof(stp));
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			for(int i=1;i<=n;i++)
			{
				int step=1;
				ll m=a[i];
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]-a[j-1]>d)
					{
						stp[i][j]=0;
						break;
					}
					if(a[j]-m<=d)
						stp[i][j]=step;
					else
					{
						m=a[j-1];
						step++;
						stp[i][j]=step;
					}
				}
			}
			//for(int i=1;i<=n;i++)
			//	for(int j=i+1;j<=n;j++)
			//		cout<<i<<' '<<j<<' '<<stp[i][j]<<'\n';
			//cout<<"\nhaha\n";
			for(int k=2;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					int j=i+k-1;
					if(j>n)
						break;
					else if(stp[i][j]==0)
					{
						dp[i][j]=0;
						continue;
					}
					if(stp[i][j]==1)
					{
						dp[i][j]=1;
						continue;
					}
					for(int l=i+1;l<j;l++)
					{
						if(stp[i][l]+stp[l][j]==stp[i][j]&&stp[i][l]==1)
						{
							//if(i==1&&j==6)
								//cout<<"!"<<l<<'\n';
							dp[i][j]+=dp[i][l]*dp[l][j];
						}
					}
				}
				//for(int i=1;i<=n;i++)
				//	for(int j=i+1;j<=n;j++)
				//		if(dp[i][j]!=0)
				//			cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
				//cout<<'\n';
			}
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(dp[i][j]==2)
						ans++;
			cout<<ans<<'\n';
		}
	}
	return 0;
}