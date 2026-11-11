//GZ-S00066 刘明远 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;

int c,t;
int n;
long long x[2000006],ans,d;
long long vis[2000006],dis[2000006];

void dfs(int u)
{
	for(int i=min(n,(int)(lower_bound(x+1+u,x+n+1,x[u]+d)-x));i>u;i--)
	{
		if(x[i]-x[u]<=d&&dis[i]>dis[u]+1)
		{
			dis[i]=dis[u]+1;
			vis[i]=1;
			dfs(i);
		}
		else if(x[i]-x[u]<=d&&dis[i]==dis[u]+1)
		{
			vis[i]++;
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
				dis[j]=0x3f3f3f3f,vis[j]=0;
			dis[i]=0;
			dfs(i);
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
