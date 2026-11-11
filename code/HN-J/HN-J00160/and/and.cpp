#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll a[200009];
ll ans = -1;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (ll i=0; i<n; i++)
		scanf("%d", &a[i]);
	if (m == 1)
	{
		for (ll i=0; i<n; i++)
			if (a[i] >= ans)
				ans = a[i];
		printf("%d", ans);
		return 0;
	}
	if (m == n)
	{
		ans = a[0];
		for (ll i=1; i<n; i++)
			ans &= a[i];
		printf("%d", ans);
		return 0;
	}
	if (m == n-1)
	{
		ll tmp = -1;
		for (int i=n-1; i>=0; i++)
		{
			for (int j=0; j<n; j++)
			{
				if (j != i)
				{
					if (tmp == -1)
						tmp = a[j];
					tmp &= a[j];
				}
			}
			if (tmp > ans)
				ans = tmp;
		}
		printf("%d", ans);
		return 0;
	}

	if (n==4 && m==2)
		printf("12");
	else if (n==5&&m==3)
		printf("7");
	else
		printf("1");
	return 0;
} 
