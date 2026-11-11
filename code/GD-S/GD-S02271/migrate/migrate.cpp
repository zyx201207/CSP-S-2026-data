#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int c,t,n,d,ans;
int maxst = 0;
int x[N];
bool vis[N];
int cnt[510][510];
vector<int> g[N];


void dfs(int x,int &e,int step)
{
	if(vis[x]) return;
	vis[x] = 1;
	if(x==e)
	{
		maxst = max(maxst,step);
		return;
	}
	for (auto i : g[x])
	{
		dfs(i,e,step+1);
	}
	return;
}
void dfs2(int x,int &s,int &e,int step)
{
	if(vis[x]) return;
	vis[x] = 1;
	if(x==e)
	{
		if(step==maxst)
		{
			cnt[s][e]++;
			if(cnt[s][e]>=2) ans++;
		}
	}
	for (auto i : g[x])
	{
		dfs2(i,s,e,step+1);
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		for (int i = 1;i>=n;i++)
		{
			scanf("%d",&x[i]);
		}
		for (int i = 1;i<=n;i++)
		{
			for (int j = 1;j<=n;j++)
			{
				if(abs(x[i]-x[j])<=d)
				{
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		for (int i = 1;i<=n;i++)
		{
			for (int j = 1;j<=n;j++)
			{
				dfs(i,j,0);
				memset(vis,0,sizeof vis);
				dfs2(i,i,j,0);
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

