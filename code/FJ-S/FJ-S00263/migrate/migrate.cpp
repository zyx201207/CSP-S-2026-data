#include <bits/stdc++.h>
using namespace std;
int c, t, n, N, ans;
long long d, x1[100000001], x2[100000001], x;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i = 0; i <= t; i++)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			if (x < 0) x1[-x]++;
			if (x > 0) x2[x]++;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if ((abs(j - i) + 1) % d == 1)
				{
					ans++;
				}
			}
		} 
		cout << ans << endl;
	}
	return 0;
}
