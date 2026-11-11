#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e3+55;
int x[N],vis[N],dis[N][N],ans[N][N];
vector<int> G[N];
int s,t;
void dfs(int now,int fa,int us)
{
	dis[s][now] = min(dis[s][now],us);
	for(auto v : G[now])
	{
		if(v != fa && !vis[v])
		{
			vis[v] = true;
			dfs(v,now,us + 1);
			vis[v] = false;
		}
	}
	return ;
}
void dfs2(int now,int fa,int us)
{
	if(us == dis[s][now])
	{
		ans[s][now] ++;
	}
	for(auto v : G[now])
	{
		if(v != fa && !vis[v])
		{
			vis[v] = true;
			dfs2(v,now,us + 1);
			vis[v] = false;
		}
	}
	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		memset(ans,0,sizeof(ans));
		for(int i = 1;i<=n;i++)
		{
			cin>>x[i];
			G[i].clear();
		}
		for(int i = 1;i<=n;i++)
		{
			for(int j = i + 1;j<=n;j++)
			{
				if(x[j] - x[i] <= d)
				{
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				dis[i][j] = 1e18;
			}
		}
		for(int i = 1;i<=n;i++)
		{
			memset(vis,false,sizeof(vis));
			s = i;
			vis[i] = true; 
			dfs(s,-1,0);
		}
		memset(vis,false,sizeof(vis));
		for(int i = 1;i<=n;i++)
		{
			memset(vis,false,sizeof(vis));
			s = i;
			vis[i] = true; 
			dfs2(s,-1,0);			
		}
		int answer = 0;
		for(int i = 1;i<=n;i++)
		{
			for(int j = i + 1;j<=n;j++)
			{
				if(ans[i][j] == 2)
				{
					answer ++;
				}
			}
		}
		cout<<answer<<endl;
	}
	return 0;
}
