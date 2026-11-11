#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define TIII tuple<int,int,int>
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define il inline
#define rg register
#define fi first
#define se second
#define MAXN 1000005
using namespace std;
int C,T,ans = 1e18,n,f[MAXN],k,vis[MAXN];
vector<int> g[MAXN];
il void rr(int u)
{
	vis[u] = 1;
	for (int v : g[u]) if (!vis[v] && f[v]) rr(v);
}
il bool chk()
{
	int sum = 0;
	for (rg int i = 1;i<=n;i++) vis[i] = 0;
	for (rg int i = 1;i<=n;i++)
	{
		if (!vis[i] && f[i])
		{
			rr(i);
			sum ++;
		} 
	} 
	return sum <= 2;
}
il void did()
{
	int maxn = 0;
	for (rg int i = 1;i<=n;i++)
	{
		if (f[i]) continue;
		for (rg int i = 1;i<=n;i++) vis[i] = 0;
		queue<PII> q;
		q.push(MP(i,0));
		vis[i] = 0;
		while (q.size())
		{
			auto [u,d] = q.front();
			q.pop();
			if (f[u])
			{
				maxn = max(maxn,d);
				break;
			}
			for (auto v : g[u])
			{
				if (!vis[v])
				{
					vis[v] = 1;
					q.push(MP(v,d + 1));
				}
			}
		}
	}
	ans = min(ans,maxn);
}
il void dfs(int step,int sum)
{
	if (step > n)
	{
		if (sum == k)
		{
			if (chk()) did();
		}
		return;
	}
	f[step] = 1;
	dfs(step + 1,sum + 1);
	f[step] = 0;
	dfs(step + 1,sum);
}
il void solve()
{
	cin>>n>>k;
	ans = 1e18;
	for (rg int i = 1;i<=n;i++) g[i].clear(),f[i] = 0;
	for (rg int i = 1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while (T --) solve();
	return 0;
}
