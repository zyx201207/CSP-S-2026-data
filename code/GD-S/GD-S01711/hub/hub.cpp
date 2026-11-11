#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

inline void write(int x)
{
	if (x > 9) write(x / 10);
	int tmp = (x % 10);
	putchar(tmp + '0');
}

int c, t, n, k, maxn, ans;
int dis[15], f[15];
vector <int> g[1000005];
bitset <15> vis;

int calc(int x)
{
	int cnt = 0;
	while (x)
	{
		cnt += (x & 1);
		x >>= 1;
	}
	return cnt;
}

void bfs(int s) 
{
	maxn = 0;
	vis.reset();
	queue <int> q;
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	for (int i = 1; i <= n; i++)
	{
		if ( (s & (1 << i - 1) ) ) 
		{
			dis[i] = 0;
			vis[i] = true;
			q.push(i);
		}
	}
		
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		maxn = max(maxn, dis[u]);
		
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i];
			if (vis[v]) continue;
			dis[v] = dis[u] + 1;
			maxn = max(maxn, dis[v]);
			q.push(v);
			vis[v] = true;
		}
	}
}

void init_bcj()
{
	for (int i = 1; i <= n; i++) f[i] = i;
}
int find(int x)
{
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;
	f[fx] = fy;
}
bool chk(int s)
{
	init_bcj();
	for (int u = 1; u <= n; u++)
	{
		if (! (s & (1 << u - 1) ) ) continue;
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i];
			if ((s & (1 << v - 1) )) merge(u, v);
		}
	}
	
	int cnt = 0;
	set <int> vis2;
	for (int i = 1; i <= n; i++)
	{
		if ( (s & (1 << i - 1) ) ) 
		{
			int fi = find(i);
			if (vis2.find(fi) == vis2.end())
			{
				cnt++;
				if (cnt > 2) return false;
				vis2.insert(fi);
			}
		}
	}
	
	return true;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	c = read(), t = read();
	while (t--)
	{
		ans = 2e9;
		for (int i = 1; i <= n; i++) g[i].clear();
		
		n = read(), k = read();
		for (int i = 1, u, v; i < n; i++)
		{
			u = read(), v = read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		if (c <= 3)
		{
			for (int s = (1 << k) - 1; s < (1 << n); s++)
			{
				if (calc(s) != k || !chk(s)) continue;
				
				bfs(s);
				ans = min(ans, maxn);
			}
			
			cout << ans << endl;
		}
	}
	return 0;
}
