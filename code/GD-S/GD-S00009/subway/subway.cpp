#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, q, w[500001], k[501], a[501][500001], t[501][500001];
vector<long long> T[500001];
bool flag = true;

long long dfs(long long ans, long long cur, long long y)
{
	if (cur == y)
	{
		return ans;
	}
	
	long long minn = -1;
	
	for (long long e : T[cur])
	{
		for (long long i = 1; i <= n; ++i)
		{
			if ((a[i][1] == cur && a[i][2] == i) || (a[i][1] == i && a[i][2] == cur))
			{
				long long s = dfs(ans + t[i][1] + t[i][2], i, y);
				
				if (minn == -1)
				{
					minn = s;
				}
				
				minn = min(minn, s);
			}
		}
	}
	
	return minn;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	
	for (long long i = 1; i <= m; ++i)
	{
		cin >> w[i];
	}
	
	for (long long i = 1; i <= n; ++i)
	{
		cin >> k[i];
		
		for (long long j = 1; j <= k[i]; ++j)
		{
			cin >> a[i][j] >> t[i][j];
		}
		
		T[a[i][1]].push_back(a[i][2]);
		T[a[i][2]].push_back(a[i][1]);
	}
	
	while (q--)
	{
		long long x, y;
		
		cin >> x >> y;
		
		cout << dfs(w[x] + w[y], x, y) << "\n";
	}
	
	return 0;
}
