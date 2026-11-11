#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, m, mid, x, lstx, ans = 0, s[N];
char ch, lstc;
struct node
{
	int sum;
	char c;
} a[N];
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x >> ch;
		if (ch == lstc) a[m]. sum += x;
		else a[++m] = {x, ch};
		lstx = x, lstc = ch;
	}
	for (int i = 1; i <= m; ++i) s[i] = s[i - 1] + a[i]. sum;
	int g = s[m] / 2;
	if (s[m] % 2 != 0) ++g;
	for (int i = 1; i <= m; ++i)
	{
		if (s[i] >= g)
		{
			mid = i;
			break;
		}
	}
	int i = 1, j = m;
	while (i <= mid)
	{
		if (a[i]. sum >= a[j]. sum)
		{
			if (a[i]. c != a[j]. c) ans += a[j]. sum;
			a[i]. sum -= a[j]. sum;
			a[j--]. sum = 0;
			if (!a[i]. sum) ++i;
		}
		else
		{
			if (a[i]. c != a[j]. c) ans += a[i]. sum;
			a[j]. sum -= a[i]. sum;
			a[i++]. sum = 0;
			if (!a[j]. sum) --j;
		}
	}
	cout << ans << endl;
	return 0;
}
