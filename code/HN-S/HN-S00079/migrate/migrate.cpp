#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mx=2e6+5;
int c,t,n,d;
int x[mx];
int cnt[mx];
int dis[mx];
bool vis[mx];
vector<int>g[mx];
void bfs(int s)
{
	queue<int>q;
	q.push(s);
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e9;
		cnt[i]=0;
		vis[i]=false;
	}
	cnt[s]=1;
	dis[s]=0;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		vis[u]=true;
		for(int v:g[u])
		{
			if(vis[v])continue;
			if(dis[v]>dis[u]+1)
			{
				cnt[v]=cnt[u];
				dis[v]=dis[u]+1;
				q.push(v);
			}
			else if(dis[v]==dis[u]+1)
			{
				cnt[v]+=cnt[u];
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			for(int j=i-1;j>=1;j--)if(x[i]-x[j]<=d)g[i].push_back(j);
			for(int j=i+1;j<=n;j++)if(x[j]-x[i]<=d)g[i].push_back(j);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=1;j<=n;j++)if(cnt[j]==2)ans++;
		}
		cout<<ans/2;
		cout<<'\n';
	}
	return 0;
}
/*

test7~10 
40pts

*/


//许愿；希望能拿一等qwq  
