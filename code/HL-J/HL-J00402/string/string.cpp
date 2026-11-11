#include <bits/stdc++.h>
using namespace std;
int n, a[200005], f, cnt = 0, st = 0;
char c[200005];
int b[200005] = {0};
char p(int m)
{
	int d = lower_bound(b + 1, b + n + 1, m) - b;
	return c[d];
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if (n == 1)
	{
		cout << "0";
		return 0; 
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		st = st + a[i];
		b[i] = b[i-1] + a[i];
	}
	for (int i = 1; i <= n - 1; i++)
	{
		if (c[i] != c[i + 1])
		{
			break;
		 } 
		cout << "0";
		return 0;
	}
	f = (st + 1) / 2;
	for (int i = 1; i <= f; i++)
	{
		if (p(i) != p(f - i + 1))
		{
			cnt++;
		}
		else
		{
			i = min(a[i], a[f - i + 1]);
		}
	}
	cout << cnt;
}
