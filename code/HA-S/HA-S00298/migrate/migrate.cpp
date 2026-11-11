#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, x[2000001], f[2000001], ans;
vector<pair<long long, long long> > g[2000001];
bool v[2000001];
priority_queue<pair<long long, long long> > q;
void dij(int x)
{
	
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
			for (int j = 1; j < i; j++)
			{
				if (i != j)
				{
					g[j].push_back(make_pair(i, x[i]-x[j]));
					f[i] = 0x7fffffff;
					f[j] = 0x7fffffff;
				}
			}
		}
		cout << g[1][1].first << '\n';
	}
	return 0;
}
