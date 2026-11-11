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

int n, d;
int c, t;
int a[2000010];

inline void solveA()
{
	while(t--)
	{
		n = read(), d = read();
		for(int i = 1;i <= n;++i) a[i] = read();
		int d1 = a[2]-a[1];
		if(n == 1 || 2*d1 > d)
		{
			puts("0");
			continue;
		}
		int t = d/d1;
		int ans = 0;
		for(int i = 1;i <= n;++i)
		{
			if(n-i >= 2*t-1) ++ans;
		}
		printf("%lld\n",ans);
	}
}

inline void solveB()
{
	while(t--)
	{
		n = read(), d = read();
		for(int i = 1;i <= n;++i) a[i] = read();
		int mid = 0;
		for(int i = 1;i <= n;++i)
		{
			if(a[n]-a[i] <= d)
			{
				mid = i;
				break;
			}
		}
		int ans = 0;
		for(int i = 1;i < mid;++i)
		{
			if(a[mid+2]-a[i] <= d) break;
			if(a[mid+1]-a[i] <= d) ++ans;
		}
		printf("%lld\n",ans);
	}
}

struct nod
{
	int x, z, t;
};

inline bool operator <(nod u, nod v)
{
	return u.z > v.z;
}

nod dis[5010];
bool vis[5010];
vector<nod> adj[5010];

inline void dij(int s)
{
	priority_queue<nod> q;
	for(int i = 1;i <= n;++i) vis[i] = 0, dis[i].z = 1e18, dis[i].t = 0;
	dis[s].z = 0;
	q.push({s,0ll,0ll});
	while(!q.empty())
	{
		nod a = q.top();
		q.pop();
//		if(vis[a.x]) continue;
		vis[a.x] = 1;
//		puts("1");
		for(nod u : adj[a.x])
		{
			if(dis[u.x].z == dis[a.x].z+u.z)
			{
				dis[u.x].t++;
				q.push({u.x,dis[u.x].z,dis[u.x].t});
			}
			if(!vis[u.x] && dis[u.x].z > dis[a.x].z+u.z)
			{
				dis[u.x].z = dis[a.x].z + u.z;
				dis[u.x].t = 1;
				q.push({u.x,dis[u.x].z,dis[u.x].t});
//				cout << dis[u.x] << ' ' << u.x << endl;
			}
		}
	}
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(), t = read();
	if(c == 11 || c == 12)
	{
		solveA();
		return 0;
	}
	if(c == 13 || c == 14)
	{
		solveB();
		return 0;
	}
	while(t--)
	{
		n = read(), d = read();
		for(int i = 1;i <= n;++i) adj[i].clear();
		for(int i = 1;i <= n;++i)
		{
			a[i] = read();
			for(int j = 1;j < i;++j)
			{
				if(a[i]-a[j] <= d)
				{
					adj[j].pb({i,1,0});
//					cout << i << ' ' << j << endl;
				}
			}
		}
		if(n == 1)
		{
			puts("0");
			continue;
		}
		int ans = 0;
		for(int i = 1;i <= n;++i)
		{
			dij(i);
			for(int j = i+1;j <= n;++j)
			{
				if(dis[j].z == 1e18) break;
				if(dis[j].t == 2)
				{
//					cout << i << ' ' << j << endl;
					++ans;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
