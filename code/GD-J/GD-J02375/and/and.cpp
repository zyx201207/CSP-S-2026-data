#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;
struct stu
{
	int x, gs;
}a[200005];
int pc(int x)
{
	int ans = 0;
	while (x)
	{
		if (x % 2)
			ans++;
		x /= 2;
	}
	return ans;
}
bool cmp(stu a, stu b)
{
	if (a.gs == b.gs)
		return a.x < b.x;
	return a.gs < b.gs;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x;
		a[i].gs = pc(a[i].x);
	}
	sort(a + 1, a + 1 + n, cmp);
	ans = a[n].x;
	for (int i = n - 1; i > n - m; i--)
	{
		ans &= a[i].x;
	}
	cout << ans;
	return 0;
}
/*4 2
3 15 12 12*/
