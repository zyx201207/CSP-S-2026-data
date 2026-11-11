#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n;ll m, a[N], s[N];

bool check(int len)
{
	for(int l = 1;l <= n - len + 1;l++)
	{
		int r = l + len - 1;
		if(s[r] - s[l - 1] + m >= a[r] * len)
			return true;
	}
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	scanf("%d%lld", &n, &m);
	for(int i = 1;i <= n;i++)scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);for(int i = 1;i <= n;i++)s[i] = s[i - 1] + a[i];
	int l = 1, r = n, res = 0;
	while(l <= r)
	{
		int m = (l + r) >> 1;
		if(check(m))l = m + 1, res = m;
		else r = m - 1;
	}
	printf("%d\n", res);
	return 0;
}
