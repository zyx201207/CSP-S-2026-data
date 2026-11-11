#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 500010;

int n, m;
int a[N], s[N];
signed main ()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	
	int Ans = 0;
	for (int i = 1; i <= n; i++) s[i] = a[i] + s[i - 1];
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i;
		while (l < r)
		{
			int mid = l + r >> 1;
			if ([=]() -> bool
			{
				int ned = a[i] * (i - mid + 1) - (s[i] - s[mid - 1]);
				return m < ned;
			}()) l = mid + 1;
			else r = mid;
		}
		Ans = max(Ans, i - l + 1);
	}
	printf("%lld\n", Ans);
	return 0;
}
// Only feels like nothing could be better when I with you, when I with you ~ 
// Dancing all night pray we're next together it's a breakthough, it's a breakthough ~
