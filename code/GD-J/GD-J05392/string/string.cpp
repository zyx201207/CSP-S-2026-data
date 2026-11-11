#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct node
{
	ll num;
	char c;
}a[200005];
ll mn, ans = 0;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].num >> a[i].c;
	int l, r;
	for (l = 1, r = n; l <= r; )
	{
		mn = min(a[l].num, a[r].num);
		if (a[l].c != a[r].c)
			ans += mn;
		a[l].num -= mn;
		a[r].num -= mn;
		if (a[l].num <= 0)
			l++;
		if (a[r].num <= 0)
			r--;
	}
	cout << ans << "\n";
	return 0;
}
