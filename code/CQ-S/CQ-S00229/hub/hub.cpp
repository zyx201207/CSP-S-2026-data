#include <bits/stdc++.h>
using namespace std;

long long cnt, head[1000005], t, n, k, fa[100005], vis[100005], ans, v[100005], sum;

struct edge
{
	long long next, to;
};
edge e[1000005];

void add(long long from, long long to)
{
	e[++cnt].to = to;
	e[cnt].next = head[from];
	head[from] = cnt;
}

long long find(long long x)
{
	if(x== fa[x])
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}

void dfs1(long long u, long long y, long long s)
{
	if(u == y)
	{
		sum = s;
		return ;
	}
	v[u] = 1;
	for(int i =head[u]; i; i = e[i].next)
	{
		long long vv = e[i].to;
		if(v[vv])
		{
			continue;
		}
		dfs1(vv, y, s + 1);
	}
}

void dfs(long long x)
{
	if(x == n + 1)
	{
		for(int i = 1; i <= n * 2; i++)
		{
			fa[i] = i;
		}
		long long sss = 0;
		for(int i = 1; i <= n; i++)
		{
			if(vis[i])
			{
				sss++;
				for(int j = head[i]; j; j = e[j].next)
				{
					if(vis[j] == 1)
					{
						long long fx = find(i), fy = find(e[j].to);
						if(fx != fy)
						{
							fa[fx] = fy;
						}
					}
				}
			}
		}
		if(sss!= k)
		{
			return ;
		}
		long long ss = 0;
		for(int i = 1; i <= n; i++)
		{
			if(vis[i] && fa[i] == i)
			{
				ss++;
			}
		}
		if(ss != 2)
		{
			return ;
		}
		long long sssss = 0;
		for(int i = 1; i <= n; i++)
		{
			long long ssss = 1e18;
			for(int j = 1; j <= n; j++)
			{
				for(int k = 1; k <= n; k++)
				{
					v[k] = 0;
				}
				if(!vis[j])
				{
					continue;
				}
				dfs1(i, j, 0);
				ssss = min(ssss,sum);
			}
			sssss = max(sssss,ssss);
		}
		ans=min(sssss, ans);
		return ;
	}
	vis[x] = 0;
	dfs(x + 1);
	vis[x] = 1;
	dfs(x + 1);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	long long c;
	cin >> c >> t;
	while(t--)
	{
		ans = 1e18;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
		{
			head[i] = 0;
		}
		cnt = 0;
		for(int i = 1; i < n; i++)
		{
			long long x, y;
			cin >> x >> y;
			add(x, y);
			add(y, x);
		}
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
