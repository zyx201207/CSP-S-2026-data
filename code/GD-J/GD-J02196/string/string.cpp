#include <bits/stdc++.h>
using namespace std;

struct stu
{
	int num;
	char fec;
} a[100005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].num >> a[i].fec;
	}
	int l = 1, r = n, lx = a[1].num, rx = a[n].num;
	while (l < r)
	{
		if (a[l].fec != a[r].fec)
		{
			sum += min(lx, rx);
		}
		if (lx == rx)
		{
			l++;
			r--;
			lx = a[l].num;
			rx = a[r].num;
		}
		else if (lx > rx)
		{
			r--;
			lx -= rx;
			rx = a[r].num;
		}
		else if (lx < rx)
		{
			l++;
			rx -= lx;
			lx = a[l].num;
		}
	}
	cout << sum << endl;
	return 0;
}
