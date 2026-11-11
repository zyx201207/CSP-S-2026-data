#include <iostream>
#include <algorithm>
typdef long long ll;
using namespace std;

int c, t, n, ans;
ll d, x[1000005];

int count_paths(int i, int j)
{
	if (j - i + 1 <= d) return 1;
	int k = lower_bound(x + 1, x + n + 1, x[i] + d) - x;
	int cnt;
	for (int a = i + 1; a <= k; a++)
	{
		cnt += count_paths(x[a], j);
	}
	return cnt;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i < n; i++)
		{
			for (int j = upper_bound(x + 1, x + n + 1, x[i] + d) - x; j <= n; j++)
			{
				if (count_paths(i, j) == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
