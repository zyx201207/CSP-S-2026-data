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
#define MAXN 2000005
using namespace std;
int T,n,m,d,q,cnt[500005],cur,dis[MAXN],vis[MAXN];
vector<PII> g[MAXN];
unordered_map<int,int> mp;
il int chg(int x,int y) {return (d + 2) * (x - 1) + y;}
il void adde(int x,int y,int z)
{
	g[x].PB(MP(y,z));
	g[y].PB(MP(x,z));
}
il int dij(int s,int e)
{
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push(MP(0,s));
	for (rg int i = 1;i<=cur;i++) dis[i] = 1e18,vis[i] = 0;
	dis[s] = 0;
	while (q.size())
	{
		auto [d,u] = q.top();
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto [v,w] : g[u])
		{
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push(MP(dis[v],v));
			}
		}
	}
	return dis[e];
}
il void solve()
{
	cin>>n>>m>>d>>q;
	mp.clear();
	for (rg int i = 1;i<=m;i++)
	{
		cnt[i] = 2;
		int x;
		cin>>x;
		int u = chg(i,1),v = chg(i,2);
		cur += 2;
		mp[u] = cur - 1,mp[v] = cur;
		g[mp[u]].clear(),g[mp[v]].clear();
		adde(mp[u],mp[v],x);
	} 
	for (rg int i = 1;i<=n;i++)
	{
		int k,las = 0;
		cin>>k;
		for (rg int j = 1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			int u = chg(x,++ cnt[x]),v = chg(x,2);
			mp[u] = ++ cur;
			g[mp[u]].clear();
			adde(mp[u],mp[v],y);
			if (j > 1) adde(mp[chg(las,cnt[las])],mp[u],0);
			las = x;
		}
	}
	while (q --)
	{
		int x,y;
		cin>>x>>y;
		int u = mp[chg(x,1)],v = mp[chg(y,1)];
		cout<<dij(u,v)<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>T;
	solve();
	return 0;
}
