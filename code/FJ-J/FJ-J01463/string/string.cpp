#include <bits/stdc++.h>
using namespace std;

int n;
int a[(int)2e5];
char c[(int)2e5];
long long ans;
void todo(int i, int j)
{
	if (i > j)
	{
		return;
	}
	
	if(c[i] == c[j])
	{
		if (a[i] == a[j])
		{
			todo(++i, --j);
		}
		else if (a[i] >= a[j])
		{
			a[i] -= a[j];
			todo(i, --j);
		}
		else if (a[i] <= a[j])
		{
			a[j] -= a[i];
			todo(++i, j);
		}
	}
	else
	{
		if (a[i] == a[j])
		{
			ans += a[i];
			todo(++i, --j);
		}
		else if (a[i] >= a[j])
		{
			a[i] -= a[j];
			ans += a[j];
			todo(i, --j);
		}
		else if (a[i] <= a[j])
		{
			a[j] -= a[i];
			ans += a[i];
			todo(++i, j);
		}
	}
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		scanf("%d %s", &a[i], &c[i]);
	}
	int i = 0;
	int j = n-1;
	todo(i, j);
	printf("%lld", ans);
	return 0;
}

