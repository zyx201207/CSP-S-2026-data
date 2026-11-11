#include <bits/stdc++.h>
using namespace std;

inline long long read()
{
	long long x = 0, f = 1;
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

inline void write(long long x)
{
	if (x > 9) write(x / 10);
	int tmp = (x % 10);
	putchar(tmp + '0');
}

int c, t, n;
long long d, ans;
long long a[2000005];

int dis[5005], cnt[5005];
bitset <5005> vis;

void bfs(int s)
{
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	vis.reset();
	dis[s] = 0, cnt[s] = 1, vis[s] = true;
	queue <int> q;
	q.push(s);
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		
		for (int v = u + 1; v <= n && a[v] - a[u] <= d; v++)
		{
			if (vis[v])
			{
				if (dis[v] + 1 == dis[u]) cnt[u] += cnt[v];
				continue;
			}
			
			dis[v] = min(dis[v], dis[u] + 1);
			q.push(v);
			vis[v] = true;
		}
		
		for (int v = u - 1; v >= 1 && a[u] - a[v] <= d; v--)
		{
			if (vis[v])
			{
				if (dis[v] + 1 == dis[u]) cnt[u] += cnt[v];
				continue;
			}
			
			dis[v] = min(dis[v], dis[u] + 1);
			q.push(v);
			vis[v] = true;
		}
	}
	
	for (int i = s + 1; i <= n; i++) 
		if (cnt[i] == 2) ans++;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--)
	{
		ans = 0;		
		n = read(), d = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		
		if (c <= 10)
		{			
			for (int i = 1; i <= n; i++) bfs(i);
			write(ans);
			putchar('\n'); 
		}
		else if (11 <= c && c <= 12)
		{
			long long di = 1ll * a[2] - 1ll * a[1];
			long long step = d / di;
			if (step <= 1) putchar('0');
			else write( max(n - 2 * step + 1, 0ll) );
			putchar('\n');
		}
		else if (13 <= c && c <= 14)
		{
			int pt1 = 0, pt2 = 0, m = 0;
			
			for (int i = 1, l, r, minl, maxr; i <= n; i++)
			{
				minl = maxr = i;
				l = 1, r = i - 1;
				while (l <= r)
				{
					int mid = (l + r) / 2;
					if (a[i] - a[mid] <= d) minl = min(minl, mid), r = mid - 1;
					else l = mid + 1;
				}
				
				l = i + 1, r = n;
				while (l <= r)
				{
					int mid = (l + r) / 2;
					if (a[mid] - a[i] <= d) maxr = max(maxr, mid), l = mid + 1;
					else r = mid - 1;
				}
				
				if (minl == 1 && maxr == n)
				{
					m++;
					if (!pt1) pt1 = i;
					else pt2 = i;
				}
			}
			
			if (m == 2)
			{
				ans = (pt1 - 1) * (n - pt2);
				write(ans);
			}
			else putchar('0');
			putchar('\n');
		}
	}
	return 0;
}
