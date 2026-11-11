#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define int long long
int n, sum, ans;
char val[MAXN];
int a[MAXN], l[MAXN], r[MAXN];
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> val[i];
		l[i] = sum + 1;
		sum += a[i];
		r[i] = sum;
	}
	int mid = sum / 2 + 1;
	for (int i = 1; i <= n; i++)
	{
		if (l[i] >= mid) break;
		int L = sum - r[i] + 1, R = sum - l[i] + 1;
		int idl = upper_bound(l + 1, l + n + 1, L) - l - 1;
		int idr = upper_bound(l + 1, l + n + 1, R) - l - 1;
		if (idl == idr)
		{
			if (val[i] != val[idl]) ans += R - L + 1;
		}
		else
		{
			if (val[i] != val[idl]) ans += r[idl] - L + 1;
			for (int j = idl + 1; j < idr; j++)
			{
				if (val[i] != val[j]) ans += r[j] - l[j] + 1;
			}
			if (val[i] != val[idr]) ans += R - l[idr] + 1;
		}
	}
	cout << ans;
	return 0;
}
