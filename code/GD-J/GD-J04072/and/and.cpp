#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, M = 32;
int n, m;
long long a[N];
long long ans;
vector<int> must;
vector<int> bit[M];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int j = 1; j <= n; ++j)
	{
		scanf("%lld", &a[j]);

		for (int i = 0; i <= 31; ++i)
			if ((a[j] >> i) & 1)
				bit[i].push_back(j);
	}

	for (int i = 31; i >= 0; --i)
	{
		sort(bit[i].begin(), bit[i].end());

		if ((int)bit[i].size() < m)
			continue;

		int can = 0;
		vector<int> nowmust;

		for (int mem : must)
		{
			int x = *lower_bound(bit[i].begin(), bit[i].end(), mem);

			if (x != mem)
			{
				continue;
			}

			can++, nowmust.push_back(mem);
		}

		if (can >= m || must.empty())
		{
			ans += (1 << i);

			if (must.empty())
				for (int mem : bit[i])
					must.push_back(mem);

			else
				must = nowmust;
		}
	}

	cout << ans;

	return 0;
}
