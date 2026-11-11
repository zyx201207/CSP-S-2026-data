#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = a[n-1];
	for(int i = n; i > n-m; i--)
	{
		ans &= a[i];
	}
	printf("%d", ans);
	return 0;
}
