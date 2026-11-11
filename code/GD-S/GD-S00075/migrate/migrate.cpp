#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int n, c, t, dist1[maxn], dist2[maxn], dist3[maxn];// dist to sttidx
long long a[maxn], d, ans;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	
	for (int i = 1;i <= t;i++)
	{
		cin >> n >> d;
		ans = 0;
		
		memset(a, 0, sizeof(a));
		for (int x = 1;x <= n;x++)
		{
			scanf("%lld", &a[x]);
		}
		
		for (int x = 1;x <= n;x++)
		{
			printf("%lld ", a[x]);
		}
		
		if (c == 11 || c == 12 || c == 0)
		{
			long long dif = a[2] - a[1];
			
			if (dif == 0)
			{
				cout << 0 << endl;
				continue;
			}
			
			if (d / dif < 2) ans = 0;
			if (d / dif >= n - 1) ans = 0;
			else
			{
				ans = n - (d / dif + 1);
			}
			
			cout << ans << endl;
		}
	}
	
	return 0;
}
