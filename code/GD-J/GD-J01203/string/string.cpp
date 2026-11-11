#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
char c[N];
int n;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		cin >> c[i];
	}
	int p = 1, q = n;
	long long ans = 0;
	while(p <= q)
	{
		if(a[p] < a[q])
		{
			if(c[p] != c[q]) ans += a[p];
			a[q] -= a[p];
			a[p++] = 0;
		}
		if(a[p] > a[q])
		{
			if(c[p] != c[q]) ans += a[q];
			a[p] -= a[q];
			a[q--] = 0;
		}
		if(a[p] == a[q])
		{
			if(c[p] != c[q]) ans += a[p];
			a[p++] = 0;
			a[q--] = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
