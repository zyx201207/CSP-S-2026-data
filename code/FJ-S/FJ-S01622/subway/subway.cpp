#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define ms(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mk make_pair

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	return x*f;
}

int c, n, m, d, q;
int w[500010];
map<pair<int,int> ,int> mp;
int tot;
map<int,int> mp1;
bool flag[500010][3];
int t1[500010][3];
vector<int> v;

inline void solve1()
{
	for(int i = 1;i <= n;++i)
	{
		int k = read();
		for(int j = 1;j <= k;++j)
		{
			int a = read(), t = read();
			flag[a][i] = 1;
			t1[a][i] = t;
			mp1[a]++;
			if(mp1[a] == 2) v.pb(a);
		}
	}
	int mmin = 1e18;
	for(int a : v) mmin = min(mmin,t1[a][1]+t1[a][2]);
	while(q--)
	{
		int x = read(), y = read();
		int s = 1e18;
		if(flag[x][1])
		{
			if(flag[y][1]) s = min(s,t1[x][1]+t1[y][1]);
			if(flag[y][2]) s = min(s,t1[x][1]+mmin+t1[y][2]);
		}
		if(flag[x][2])
		{
			if(flag[y][2]) s = min(s,t1[x][2]+t1[y][2]);
			if(flag[y][1]) s = min(s,t1[x][2]+mmin+t1[y][1]);
		}
		printf("%lld\n",w[x]+w[y]+s);
	}
}

struct nod
{
	int x, z;
};

inline bool operator <(nod u, nod v)
{
	return u.z > v.z;
}

int dis[1000010];
bool vis[1000010];
vector<nod> adj[1000010];

inline void dij(int s)
{
	priority_queue<nod> q;
	for(int i = 1;i <= tot;++i) vis[i] = 0, dis[i] = 1e18;
	dis[s] = 0;
	q.push({s,0ll});
	while(!q.empty())
	{
		nod a = q.top();
		q.pop();
		if(vis[a.x]) continue;
		vis[a.x] = 1;
//		puts("1");
		for(nod u : adj[a.x])
		{
			if(!vis[u.x] && dis[u.x] > dis[a.x]+u.z)
			{
				dis[u.x] = dis[a.x] + u.z;
				q.push({u.x,dis[u.x]});
//				cout << dis[u.x] << ' ' << u.x << endl;
			}
		}
	}
}

inline void solve()
{
	for(int i = 1;i <= n;++i)
	{
		int k = read();
		int last = 0;
		for(int j = 1;j <= k;++j)
		{
			int a = read(), t = read();
			mp[mk(i,a)] = ++tot;
			if(last) adj[tot].pb({mp[mk(i,last)],0ll}), adj[mp[mk(i,last)]].pb({tot,0ll});
			adj[tot].pb({a,t});
			adj[a].pb({tot,t});
			last = a;
		}
	}
	while(q--)
	{
		int x = read(), y = read();
		dij(x);
		printf("%lld\n",w[x]+w[y]+dis[y]);
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1;i <= m;++i) w[i] = read(), mp[mk(0ll,i)] = ++tot;
	if(n <= 2) solve1();
	else solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
