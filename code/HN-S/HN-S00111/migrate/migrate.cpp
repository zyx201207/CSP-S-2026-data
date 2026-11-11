#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e6+10,maxl=1e3+10,inf=1e18;
int rp,T,n,d;
int a[N],dp[N];
int dis[maxl][maxl];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>rp>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=1;j<=n;j++) dis[i][j]=0;
		}
		for(int i=1;i<=n;i++)
		{
			fill(dp+1,dp+n+1,inf);
			for(int j=1;j<=i;j++) dp[i]=0;
			for(int j=1;j<=n;j++)
			{
				for(int k=j;k>=1;k--)
				{
					if(a[j]-a[k]<=d) dp[j]=max(dp[j],dp[k]+1);
					else break;
				}
			}
			for(int j=1;j<=n;j++)
			{
				for(int k=j;k>=1;k--)
				{
					if(a[j]-a[k]<=d)
					{
						if(dp[j]==dp[k]+1) dis[i][j]++;
					}
					else break;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
