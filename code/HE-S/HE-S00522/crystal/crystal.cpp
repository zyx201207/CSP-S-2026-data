#include <bits/stdc++.h>
using namespace std;

long long n, m, e, cnt = 0, sum = 0, ave = 0, minn = 1e12;

struct node
{
	long long w;
	long long q;
};
node a[500005];

bool cmp (node x, node y)
{
	return x.q < y.q;
}

int main()
{
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].w;
		sum += a[i].w;
	}
	ave = sum / n;
	for (int i = 1; i <= n; i++)
	{
		if (abs(ave - a[i].w) < minn)
		{
			minn = abs(ave - a[i].w);
			e = a[i].w;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		a[i].q = abs(e - a[i].w);
	}
	sort (a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (a[i].q == 0)
		{
			cnt++;
		}
		else
		{
			m -= a[i].q;
			if (m < 0)
			{
				break;
			}
			else
			{
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
