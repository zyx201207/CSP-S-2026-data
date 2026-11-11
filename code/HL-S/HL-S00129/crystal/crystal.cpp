#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 500010;

int n;
LL m;
LL a[N], d[N];
LL s[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
	
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
	
	int l = 1, res = 1;
	for (int i = 1; i <= n; i ++ )
	{
		LL need = (LL)(i - l + 1) * a[i] - s[i] + s[l - 1];
		while (need > m && l < i)
		{
			l ++ ;
			need = (LL)(i - l + 1) * a[i] - s[i] + s[l - 1];
		}
		res = max(res, i - l + 1);
	}
	
	printf("%d\n", res);
	return 0;
}
