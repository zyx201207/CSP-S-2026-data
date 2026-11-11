#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 2;
int C, T, n, L[N], R[N], f[N];
ll d, x[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 1, j = 1, k = 1; i <= n; i++)
		{
			while (x[i] - x[j] > d) j++;
			while (k < n && x[k + 1] - x[i] <= d) k++;
			L[i] = j, R[i] = k;
		}
		if (C == 13 || C == 14)
		{
			if (x[n] - x[1] <= d)
			{
				cout << 0 << endl;
				continue;
			}
			int cnt = 0;
			for (int i = 1; i <= n; i++)
				if (L[i] == 1 && R[i] == n)
					cnt++;
			if (cnt > 2)
				cout << 0 << endl;
			if (cnt == 2)
				for (int i = 1; i <= n; i++)
					if (L[i] == 1 && R[i] == n)
					{
						cout << (ll)(n - R[i - 1]) * (L[i + 2] - 1) << endl;
						break;
					}
			if (cnt == 1)
				for (int i = 1; i <= n; i++)
					if (L[i] == 1 && R[i] == n)
					{
						cout << (i != 2) * (ll)(L[i + 1] - 1) * (R[i - 1] - R[i - 2]) +
						(i != n - 1) * (ll)(L[i + 2] - L[i + 1]) * (n - R[i - 1]) << endl;
					}
			continue;
		}
		ll ans = 0;
		memset(f + 1, 0, sizeof (int) * n);
		for (int i = 1; i <= n; i++)
		{
			f[i] = 1;
			for (int j = i - 1, last = i, dis = 1; j; j--)
			{
				if (x[j + 1] - x[j] > d) break;
				if (x[last] - x[j] > d) last = j + 1, dis++;
				if (dis == 1) f[i] = 1;
				else if (last == R[j]) f[j] = f[last];
				else if (last + 1 == R[j]) f[j] = min(f[last] + f[R[j]], 3);
				else f[j] = 3;
				ans += f[j] == 2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
