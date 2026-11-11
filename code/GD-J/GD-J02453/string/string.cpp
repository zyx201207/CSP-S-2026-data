#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char s[200005];
unsigned int sum = 0;
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> s[i];
		cnt += a[i];
	}
	// cout << cnt << endl;
	int st = a[1], en = a[n];
	int i = 1, j = n;
	while (i < j)
	{
		if (s[i] == s[j])
		{
			if (st > en)
			{
				st -= en;
				en = a[--j];
			}
			else if (st == en)
			{
				en = a[--j];
				st = a[++i];
			}
			else
			{
				en -= st;
				st = a[++i];
			}
			// cout << "done";
		}
		else
		{
			int mn = min(en, st);
			sum += mn;
			st -= mn;
			en -= mn;
			if (st == 0)
			{
				a[i] = 0;
				st = a[++i];
			}
			if (en == 0)
			{
				a[j] = 0;
				en = a[--j];
			}
		}
		a[i] = st;
		a[j] = en;
	}
	// cout << i << j;
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
