#include <bits/stdc++.h>
using namespace std;

vector<int> g[500505];
int x[500505];
int vis[500505],dist[500505];
int cnt[500505];
void bfs(int s)
{
	int q[500005];
	int f=0,r=0;
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	dist[s]=0;
	q[++r]=s;
	while(f<r)
	{
		int top=q[++f];
		for(int i = 0;i<g[top].size();i++)
		{
			
			int v = g[top][i];
			vis[v]++;
			if(vis[v]==1)
			{
				q[++r]=v;
				dist[v]=dist[top]+1;
				cnt[v]++;
			}
			else if(dist[v]==dist[top]+1)
			{
				cnt[v]++;
			}
			if(vis[v]>2)continue;
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i = 1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i = 1;i<=n;i++)
		{
			g[i].clear();
			for(int j = i+1;j<=n;j++)
			{
				if(x[j]-x[i]>d)break;
				else 
				{
					g[i].push_back(j);
				}
			}
		}
		int ans = 0;
		for(int i = 1;i<=n;i++)
		{
			bfs(i);
			for(int j = i+1;j<=n;j++)
			{
				if(cnt[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
