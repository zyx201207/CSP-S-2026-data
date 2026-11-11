#include <bits/stdc++.h>
using namespace std;
int C,T,n;
long long d,a[2000001];
vector<long long>g[2000001];
bool vis[2000001];
struct node
{
	int x;
	long long t;
};
bool bfs(int u,int v)
{
	queue<node>q;
	q.push({u,0});
	vector<long long>ans;
	while (!q.empty())
	{
		int xx=q.front().x;
		long long tt=q.front().t;
		q.pop();
		if (xx==v)
		{
			ans.push_back(tt);
			continue;
		}
		vis[xx]=true;
		for (int e:g[xx])
			if (!vis[e])
				q.push({e,tt+1});
	}
	sort(ans.begin(),ans.end());
	if (ans[0]==ans[1]&&ans[1]!=ans[2])
		return true;
	return false;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while (T--)
	{
		long long sum=0;
		scanf("%d%lld",&n,&d);
		for (int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (a[j]-a[i]<=d)
				{
					g[i].push_back(j);
					g[j].push_back(i);	
				}	
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
			{
				bool flag=bfs(i,j);
				memset(vis,false,sizeof vis);
				if (flag)
					sum++;
			}
		printf("%lld\n",sum);
		for (int i=1;i<=n;i++)
			g[i].clear();
	}	
} 
