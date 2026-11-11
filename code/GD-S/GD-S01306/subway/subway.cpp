#include<bits/stdc++.h>
using namespace std;
const int N = 505, D = 23, M = 5e5 + 10;
#define int long long
int c, n, m, d, q;
int w[M];
const long long inf = 1e18 + 10;
vector<pair<int, int> > g[M];
vector<pair<int, int> > e[N];
long long f[N][N];
struct node
{
	int x;
	long long dis;
	
	bool operator < (const node &x) const
	{
		return dis > x.dis;
	}
};
bool vis[N][N];
long long dis[N][N];

char buf[1 << 20], *p1 = buf, *p2 = buf;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)

int read()
{
	int x = 0;
	char c = gc();
	while(!isdigit(c)) c = gc();
	while(isdigit(c))
	{
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = gc();
	}
	return x;
}

void write(long long x)
{
	if(x < 10)
	{
		putchar(x + '0');
		return;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read(); 
	for(int i = 1; i <= m; i++)
		w[i] = read();
	for(int i = 1; i <= n; i++)
	{
		int k = read();
		for(int j = 1; j <= k; j++)
		{
			int a = read(), t = read();
			g[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			f[i][j] = inf, f[i][i] = 0;
	for(int i = 1; i <= m; i++)
		for(auto v : g[i])
			for(auto w : g[i])
				f[v.first][w.first] = min(f[v.first][w.first], (long long)v.second + w.second);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			e[i].push_back({j, f[i][j]});
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			dis[i][j] = inf;
		dis[i][i] = 0;
		priority_queue<node> pq;
		pq.push({i, 0});
		while(pq.size())
		{
			int x = pq.top().x;
			pq.pop();
			if(vis[i][x]) continue;
			vis[i][x] = 1;
			for(auto tw : e[x])
			{
				int v = tw.first, w = tw.second;
				if(dis[i][v] > dis[i][x] + w)
				{
					dis[i][v] = dis[i][x] + w;
					pq.push({v, dis[i][v]});
				}
			}
		}
	}
	while(q--)
	{
		int x = read(), y = read();
		long long ans = inf;
		for(auto v : g[x])
			for(auto w : g[y])
				ans = min(ans, (long long)v.second + w.second + dis[v.first][w.first]);
		write(ans + w[x] + w[y]);
		puts("");
	}
	return 0;
}
