#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 2e6 + 5;
const int INF = 1e9;

int c, T;
int n;
LL d, a[N];

int mind[N];
LL cnt[N], sum[N];
LL res;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> c >> T;
	while (T -- )
	{
		res = 0;
		
		cin >> n >> d;
		for (int i = 1; i <= n; i ++ ) cin >> a[i];

		if (c <= 10)		
		{
			for (int u = 1; u <= n; u ++ )
			{
				mind[u] = cnt[u] = 1;
				for (int v = u + 1; v <= n; v ++ )
					mind[v] = INF, cnt[v] = 0;
				int l = u;
				for (int v = u + 1; v <= n; v ++ )
				{
					while (l < v && a[v] - a[l] > d) l ++ ;

					mind[v] = mind[l] + 1;
					for (int i = l; i < v && cnt[v] <= 2; i ++ )					
					{
						if (mind[i] > mind[l]) break;
						cnt[v] += cnt[i];
					}
					if (cnt[v] == 2) 
						res ++ ;
					else if (cnt[v] > 2)
						cnt[v] = INF;
				}
			}
		}
		else if (11 <= c && c <= 12)
		{
			LL s = a[2] - a[1];
			if (d <= s) res = 0;
			else
			{
				LL p = d / s;
				res = max(0LL, n - p * 2 + 1);
			}
		}
		else
			res = (LL)(n - 1) * (LL)(n - 2) / 2;
		
		cout << res << '\n';
	}

	return 0;
}
