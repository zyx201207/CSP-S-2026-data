#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c, t, d, x[2000005], flag, num;
ll n;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &c, &t);
	while (t--)
	{
		flag = 1;
		scanf("%d %d", &n, &d);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x[i]);
			if (i > 1)
			{
				if (i == 2)
					num = x[i] - x[i - 1];
				else if (x[i] - x[i - 1] != num)
					flag = 0;
			}
		}
		if (flag == 1)
			cout << n * (n - 1) << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}
