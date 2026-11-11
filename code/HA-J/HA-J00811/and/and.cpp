#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool flag = true;
int check(int n)
{
	for (int i = 1;i <= n;i *= 2)
	{
		if (n == i) return true;
	}
	return false;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if (!check(n))
	{
		flag = false;
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != i - 1)
		{
			flag = false;
		}
	}
	sort(a + 1,a + n + 1);
	if (m == 1)
	{
		cout << a[n];
		return 0;
	}
	if (m == n)
	{
		cout << 0;
		return 0;
	}
	if (flag == true)
	{
		cout << a[n] - m;
		return 0;
	}
	cout << a[n];
	return 0;
	sort(a + 1,a + n + 1);
	return 0;
}
