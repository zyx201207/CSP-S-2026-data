#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e6 + 10,inf = 0x7f7f7f7f;
int n,k,ans,mxdep[N],mndep[N],did1[N],did2[N];
bool chn[N],vis[N];
vector <int> g[N];
queue <pair <int,int>> q;
void Inputtt()
{
	for(int i = 1;i <= n;i++)
	{
		g[i].clear();
		chn[i] = vis[i] = false;
	}
	cin >> n >> k;
	for(int i = 1,u,v;i < n;i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}
void dfs(int p,int fa)
{
	mxdep[p] = 0,mndep[p] = inf;
	did1[p] = did2[p] = 0;
	for(int x : g[p])
	{
		if(x == fa)
			continue;
		dfs(x,p);
		if(mxdep[x] + 1 > mxdep[p])
		{
			mxdep[p] = mxdep[x] + 1;
			did1[p] = x;
		}
		else if(mndep[x] + 1 < mndep[p])
		{
			mndep[p] = mndep[x] + 1;
			did2[p] = x;
		}
	}
	if(g[p].size() == 1)
		mndep[p] = 0;
}
void check(int p)
{
	vis[p] = true;
	for(int x : g[p])
		if(!vis[x])
			check(x);
}
void Solve(int dep)
{
	if(dep == k + 1)
	{
		int tot = 0;
		for(int i = 1;i <= n;i++)
			vis[i] = false;
		for(int i = 1;i <= n;i++)
		{
			if(chn[i] && !vis[i])
			{
				tot++;
				check(i);
			}
		}
		if(tot > 2)
			return;
		int res = 0;
		for(int i = 1;i <= n;i++)
		{
			if(chn[i])
				continue;
			for(int j = 1;j <= n;j++)
				vis[j] = false;
			while(!q.empty())
				q.pop();
			q.push(make_pair(0,i));
			vis[i] = true;
			while(!q.empty())
			{
				pair <int,int> f = q.front();
				q.pop();
				if(chn[f.second])
				{
					res = max(res,f.first);
					break;
				}
				f.first++;
				for(int x : g[f.second])
				{
					if(!vis[x])
					{
						vis[x] = true;
						q.push(make_pair(f.first,x));
					}
				}
			}
		}
		ans = min(ans,res);
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!chn[i])
		{
			chn[i] = true;
			Solve(dep + 1);
			chn[i] = false;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--)
	{
		Inputtt();
		ans = inf;
		Solve(1);
		cout << ans << '\n';
	}
	return 0;
}

