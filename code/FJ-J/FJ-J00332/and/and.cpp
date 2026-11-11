#include <bits/stdc++.h>
using namespace std;
int a[1000005];
long long n, num;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	int t = (a[1] & a[2]);
	int g = (t & a[3]);
	cout << g;
	return 0;
}
