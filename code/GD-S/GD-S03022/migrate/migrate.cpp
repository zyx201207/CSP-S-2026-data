#include <bits/stdc++.h>
using namespace std;

long long c, T;
long long n, d;
long long a[5005];
struct Node
{
	long long x;
	long long step;
};
struct Distance
{
	long long val;
	long long num;
	void rst()
	{
		val = 0;
		num = 0;
	}
} mdis[5005][5005];
vector<vector<long long>> g(5005);
void f(long long s)
{
	queue<Node> q;
	q.push({s, 0});
	while (!q.empty())
	{
		Node t = q.front();
		q.pop();
		if (mdis[s][t.x].num == 0 && t.x != s)
		{
			mdis[s][t.x].val = t.step;
			mdis[s][t.x].num = 1;
		}
		else if (mdis[s][t.x].num != 0 && t.x != s)
		{
			if (t.step != mdis[s][t.x].val)
				continue;
			mdis[s][t.x].num++;
		}

		for (long long i = 0; i < (long long)g[t.x].size(); i++)
		{
			q.push({g[t.x][i], t.step + 1});
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> T;
	while (T--)
	{
		cin >> n >> d;
		for (long long i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		for (long long i = 1; i <= n; i++)
		{
			g[i] = {};
			for (long long j = 1; j <= n; j++)
			{
				if (i != j && max(a[i], a[j]) - min(a[i], a[j]) <= d)
				{
					g[i].push_back(j);
				}
				mdis[i][j].rst();
			}
		}
		long long ans = 0;
		for (long long i = 1; i <= n; i++)
			f(i);
		for (long long i = 1; i <= n; i++)
		{
			for (long long j = i; j <= n; j++)
			{
				if (i != j && mdis[i][j].num == 2)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
