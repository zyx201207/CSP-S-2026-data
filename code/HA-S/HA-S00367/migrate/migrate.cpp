#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510;
int x[N];
int dis[N][N];
int cnt[N][N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++)
		{
			dis[i][i]=0;
			int lim=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			for(int j=i+1;j<=lim;j++)
			{
				dis[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(i==k||j==k) continue;
					int nsum=dis[i][k]+dis[k][j];
					if(dis[i][j]>nsum)
					{
						dis[i][j]=nsum;
						cnt[i][j]=1;
					}
					else if(dis[i][j]==nsum)
					{
						cnt[i][j]++;
					}
				}
			 } 
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(cnt[i][j]==2) 
				{
//					cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

