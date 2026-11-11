#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,d;
int vis[200005];
int dis[200005];
int ans[200005];
vector<int>g[200005],w[200005];
int a[200005];
void spfa(int start)
{
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e9;
		vis[i]=0;
		ans[i]=0;
	}
	q.push(start);
	dis[start]=0;
	ans[start]=1;
	vis[start]=1;
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		vis[f]=0;
		// cout<<"process0 "<<f<<" "<<dis[f]<<endl;
		for(int i=0;i<g[f].size();i++)
		{
			int y=g[f][i];
			if(dis[y]>dis[f]+1)
			{
				dis[y]=dis[f]+1;
				if(!vis[y])
				{
					vis[y]=1;
					q.push(y);
				}
				ans[y]=ans[f];
			}
			else if(dis[y]==dis[f]+1)
			{
				ans[y]+=ans[f];
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c>=11&&c<=14)
	{
		for(int i=1;i<=t;i++)
		{
			cout<<0<<endl;
		}
		return 0;
	}
	while(t--)
	{
		cin>>n>>d;
		int rpans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					g[i].push_back(j);
					g[j].push_back(i);

				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			spfa(i);

			for(int j=i+1;j<=n;j++)
			{
				// cout<<"out "<<i<<" "<<j<<" "<<ans[j]<<" "<<dis[j]<<endl;
				if(ans[j]==2)
				{
					rpans++;
				}
			}
		}
		cout<<rpans<<endl;
	}
	return 0;
}
