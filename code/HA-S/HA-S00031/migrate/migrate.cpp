#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010;
bool mp[N][N];
int x[N],dis[N],dp[N];
int n,d;
void bfs(int st)
{
	memset(dis,0x3f,sizeof(dis));
	memset(dp,0,sizeof(dp));
	queue<int>q;
	q.push(st);
	dis[st]=0;
	while(q.size())
	{
		int t=q.front();
		q.pop();
		for(int i=t+1;i<=n;i++)
		{
			if(mp[t][i]==1&&dis[t]+1<dis[i])
			{
				dis[i]=dis[t]+1;
				dp[i]=1;
				q.push(i);
			}
			else if(mp[t][i]==1&&dis[t]+1==dis[i])
			{
				dp[i]++;
				q.push(i);
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)
	{
		memset(mp,0,sizeof(mp));
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					mp[i][j]=1;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++)
			{
//				cout<<dis[j]<<" "<<dp[j]<<endl;
				if(dp[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//CCF我求你了给我24分吧 
