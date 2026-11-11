#include <bits/stdc++.h>
using namespace std;

const int NR = 2e6 + 5;

int n, d;
int cnt, cntz, l;
bool vis[NR];
int a[NR], ans[505];

void init()
{
	memset(a, 0, sizeof(0));
	cnt = cntz = 0;
	memset(ans, 0, sizeof(ans));
	return ;
}

void dfs(int u, int v, int sum)
{
	if(u == v)
	{
		ans[++cnt] = sum;
		return ;
	}
	for(int i = u + 1; i <= n; i++)
		if(a[i] - a[u] <= d)
			dfs(i, v, sum + 1);
	return ;
}

bool is_(int x, int y)
{
	memset(ans, 0, sizeof(ans));
	cnt = l = 0;
	dfs(x, y, 0);
	int minn = 1e9;
	for(int i = 1; i <= cnt; i++)
		minn = min(minn, ans[i]);
	int cnt1 = 0;
	for(int i = 1; i <= cnt; i++)
		if(ans[i] == minn) cnt1++;
	return (cnt1 == 2);
}

void work()
{
	cin >> n >> d;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int u = 1; u < n; u++)
		for(int v = u + 1; v <= n; v++)
			if(is_(u, v))
				cntz++;
	cout << cntz << "\n";
	return ;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		init();
		work();
	}
	return 0;
}
