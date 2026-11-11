#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
long long c,t,n,d,x[N],f[N],ans[N],vis[N],answer;
vector<long long> e[N];
void bfs(int s)
{
	queue<pair<long long,long long>> q;
	for(int i=0;i<=n+5;i++)
	{
		f[i]=4e18;
		ans[i]=vis[i]=0;
	}
	f[s]=0;
	ans[s]=1;
	q.push({0,s});
	while(q.size())
	{
		long long u=q.front().second,ds=q.front().first;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int v:e[u])
		{
			if(ds+1<f[v])
			{
				f[v]=ds+1;
				ans[v]=ans[u];
				q.push({f[v],v});
			}
			else if(ds+1==f[v])ans[v]+=ans[u];
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)e[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++)
			{
				if(ans[j]==2)answer++;
			}
		}
		cout<<answer<<"\n";
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
			x[i]=0;
		}
		answer=0;
	}
	return 0;
}
