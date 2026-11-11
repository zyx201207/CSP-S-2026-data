//Oct31==Dec25?
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
long long d,ans,a[N],dis[N][N],dp[N][N];
int c,t,n,vis[N];
int main()
{
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=dp[i][j]=0;
		for(int i=1;i<=n;i++)cin>>a[i],dp[i][i]=1;
		for(int i=1;i<=n;i++)
		{
			int j=i;
			while(j<=n&&a[j]-a[i]<=d)++j;
			vis[i]=j-1;
		}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				int k=i,tmp=0;
				while(k<j&&k!=vis[k])k=vis[k],tmp++;
				if(k>=j)dis[i][j]=tmp;
				else dis[i][j]=1e9;
			}
		for(int len=1;len<n;len++)
			for(int i=1;i+len<=n;i++)
				for(int j=i+1;j<=vis[i];j++)
					if(dis[j][i+len]==dis[i][i+len]-1)
						dp[i][i+len]+=dp[j][i+len];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans+=(dp[i][j]==2);
		cout<<ans<<"\n";
	}
	return 0;
}//
