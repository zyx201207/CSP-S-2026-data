#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t;
ll a[2000010];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t --)
	{
		int n;
		ll d;
		scanf("%d%lld", &n, &d);
		for (int i = 1;i <= n;i ++)
		{
			scanf("%lld", &a[i]);
		}
		int x = a[2] - a[1];
		if (d < 2 * x)
		{
			cout << 0 << endl;
			continue;
		}
		int mx = x, o = 2;
		while (x * o <= d)
		{
			o ++;
		}
		o --;
		cout << n - (o + 2) + 1 << endl;
		
	}
	return 0;
}
