#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e6 + 10, inf = 1e18;
int c;
int n, a[N], d;
int f[N], g[N];

void solve()
{
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    if (n <= 2)
    {
        cout << "0\n";
        return ;
    }
    if (c == 11 || c == 12)
    {
        int x = a[2] - a[1];
        for (int i = 2; 2 * i - 1 <= n; ++i)
        {
	        if (d >= i * x && d < (i + 1) * x)
	            return cout << n - (2 * i - 1) << '\n', void();
		}
        cout << "0\n";
        return ;
    }
    if (c <= 6)
    {
    	int ans = 0;
		for (int st = 1; st <= n; ++st)
		{
			for (int i = 1; i <= n; ++i)
				f[i] = inf, g[i] = 1;
			f[st] = 0, g[st] = 1;
			for (int j = st + 1; j <= n; ++j)
			{
				for (int k = st; k < j; ++k)
				{
					if (a[j] - a[k] <= d && f[k] != inf)
					{
						if (f[k] + 1 < f[j])
							f[j] = f[k] + 1, g[j] = g[k];
						else if (f[k] + 1 == f[j])
							g[j] = min(3ll, g[j] + g[k]);
					}
				}
				if (g[j] == 2)
					++ans;
//				cerr << st << ' ' << j << ' ' << f[j] << ' ' << g[j] << '\n';
			}
		}
		cout << ans << '\n';
		return ;
	}
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0), cout.tie(0);
    int T;
    cin >> c >> T;
    while (T--)
        solve();
    return 0;
}
