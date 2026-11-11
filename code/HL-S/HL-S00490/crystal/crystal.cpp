#include <bits/stdc++.h>

#define ll long long
#define db double

#define ls k << 1
#define rs k << 1 | 1

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

#define lowbit(x) x & (-x)

using namespace std;

const int N = 5e5 + 10;

ll n, m, a[N], ans, num;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m), ans = num = 0;
	for(int i = 1; i <= n; ++ i) scanf("%lld", &a[i]);
	
	sort(a + 1, a + n + 1);
	
	for(int i = 1, j = 1; i <= n; ++ i)
	{
		num += (i - j) * (a[i] - a[i - 1]);
		while(num > m && j < i) num -= (a[i] - a[j]), ++ j;
		ans = max(ans, i - j + 1);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}