#include <bits/stdc++.h>
using namespace std;
long long m, n, a[200005];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	long long maxn = -1;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1, cmp);
	
	long long k;
	
	for (int i = 1; i <= n - m + 1; i++)
	{
		k = a[i];
		for (int j = i + 1; j < i + m; j++)
		{
			k = (k & a[j]);
		}
		maxn = max(maxn, k);
	}
	
	cout << maxn;
	return 0;
}
