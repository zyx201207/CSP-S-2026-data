#include<bits/stdc++.h>
using namespace std;

long long c, n, t, d, cnt, sum;
long long x[2000006], a[2000006];

void in(long long &x)
{
	long long s = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		s = s * 10 + (c - '0');
		c = getchar();
	}
	x = s * f;
}

void dfs(long long u, long long v, long long num)
{
	if (sum > 2) return;
	if (a[num + 1] == v)
	{
		if (x[v] - x[u] <= d) sum ++;
		return;
	} 
	else 
	{
		for (int i = a[num] + 1; i <= a[num + 1]; i ++)
		{
			if (x[i] - x[u] > d) return;
			dfs(a[i], v, num + 1);
		} 
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	in(c); in(t);
	while (t --)
	{
		long long ans = 0;
		in(n); in(d);
		for (int i = 1; i <= n; i ++) in(x[i]);
		for (int i = 1; i <= n; i ++)
		{
			for (int j = i + 2; j <= n; j ++)
			{
				sum = 0;
				if (x[i + 1] - x[i] > d) break;
				else if (x[j] - x[i] <= d) continue;
				bool f = 1;
				cnt = 1; a[1] = i;
				int las = i;
//				cout << i << ' ' << j << endl;
				for (int k = i + 1; k < j;)
				{
//					cout << "k=" << k << endl;
					while (x[k + 1] - x[las] <= d && k < j) 
					{
//						cout << x[k + 1] << ' ' << x[las] << endl;
						k ++;
					}
					a[++ cnt] = k; las = k;
//					cout << cnt << ' ' << a[cnt] << ' ' << endl;
					if (k < j && x[k + 1] - x[k] > d) 
					{
						f = 0;
						break;
					}
				}
				if (f == 0) break;
				dfs(i, j, 1);
				if (sum == 2) ans ++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

