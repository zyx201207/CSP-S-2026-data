#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&~x) 
using namespace std;
const int N=1e5+10;
vector<int>e[N];
int chs[N],n,k,d[N],ans=0;
bool vis[N];
void col(int u)
{
	vis[u]=1;
	for(auto v:e[u])
	{
		if(vis[v]||!chs[v])
		{
			continue;
		}
		col(v);
	}
}
bool check()
{
	memset(vis,0,sizeof(vis));
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(chs[i]&&!vis[i])
		{
			col(i);
			tot++;
		}
		if(tot>2)
		{
			return 0;
		}
	}
	return 1;
}
queue<int>q;
void solve()
{
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
	{
		if(chs[i])
		{
			q.push(i);
		}
	}
	int res=0;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		res=max(res,d[u]);
		for(auto v:e[u])
		{
			if((!chs[v]&&d[v])||chs[v])
			{
				continue;
			}
			d[v]=d[u]+1;
			q.push(v);
		}
	}
	ans=min(ans,res);
}
void dfs(int u,int rst)
{
	if(rst==0)
	{
		if(check())
		{
//		for(int i=1;i<=n;i++)
//		{
//			cout<<chs[i]<<' ';
//		}
//		getchar();
			solve();
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!chs[i])
		{
			chs[i]=1;
			dfs(i,rst-1);
			chs[i]=0;
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=INT_MAX;
		dfs(1,k);
		cout<<ans<<'\n';
	}
}

