#include <bits/stdc++.h>
using namespace std;

long long c, t, n, d, x[2000001];

void dfs(long long u, long long v, long long k, long long& minn, long long& cnt)
{
	if (u == v)
	{
		if (k == minn)
		{
			++cnt;
		}
		
		else if (k < minn)
		{
			minn = k;
			cnt = 1;
		}
	}
	
	for (long long i = u + 1; i <= v; ++i)
	{
		if (x[i] - x[u] <= d)
		{
			dfs(i, v, k + 1, minn, cnt);
		}
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	
	while (t--)
	{
		long long ans = 0;
		
		cin >> n >> d;
		
		for (long long i = 1; i <= n; ++i)
		{
			cin >> x[i];
		}
		
		for (long long i = 1; i <= n; ++i)
		{
			for (long long j = 1; j < i; ++j)
			{
				long long cnt = 0, minn = i - j;
				
				dfs(j, i, 0, minn, cnt);
				
				if (cnt == 2)
				{		
					++ans;
				}
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
