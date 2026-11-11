#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N(2e5 + 5);
int m;
struct stu
{
	int num, num1;
} a[N];
bool cmp(const stu &a, const stu &b)
{
	if (m > 30)
	{
		if (a.num == b.num)
		{
			return a.num1 > b.num1;
		}
		return a.num > b.num;
	}
	if (a.num1 == b.num1)
	{
		return a.num > b.num;
	}
	return a.num1 > b.num1;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n, ans;
	cin >> n >> m;
	for (int i = 1, temp, num; i <= n; i++)
	{
		num = 0;
		cin >> a[i].num; 
		temp = a[i].num;
		while (temp)
		{
			if (temp % 2)
			{
				num++;
			}
			temp /= 2;
		}
		a[i].num1 = num;
	}
	sort(a + 1, a + n + 1, cmp);
//	for (int i = 1; i <= n; i++)
//	{
//		cout << a[i].num1 << ' ' << a[i].num << '\n';
//	}
	ans = a[1].num;
	for (int i = 2; i <= m; i++)
	{
		ans &= a[i].num;
	}
	cout << ans;
	return 0;
}
