#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
int c,t,n,dis[2000001],cnt[2000001];
bool vis[5001][5001];
long long d,x[2000001],ans=0;
vector<int> g[2000001];
void bfs(int s)
{
	for(int i=1;i<=n;i++) dis[i]=1e9;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:g[u])
		{
			if(dis[v]!=1e9) continue;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
void dp(int s)
{
	for(int i=1;i<=n;i++) cnt[i]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) vis[j][i]=false;
	cnt[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:g[u])
		{
			if(dis[v]==dis[u]+1&&!vis[u][v])
			{
				cnt[v]+=cnt[u];
				q.push(v);
				vis[u][v]=true;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==2) ans++;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) g[i].clear();
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(n<=3)
		{
			cout<<0<<"\n";
			continue;
		}
		if(c==11||c==12)
		{
			long long g=x[2]-x[1];
			if(g>=d)
			{
				cout<<0<<"\n";
				continue;
			}
			cout<<max(0ll,n-2*(d/g)+1)<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(x[i]-x[j]>d) break;
				g[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			dp(i); 
		}
		cout<<ans<<"\n";
	}
	return 0;
}

