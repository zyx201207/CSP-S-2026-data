#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n, m;
int a[N];
signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    //cin.tie(nullptr), cout.tie(nullptr);
    //ios::sync_with_stdio(false);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i<=n; i++)
		scanf("%lld", &a[i]);
	if(m==1)
	{
		int maxn = LONG_LONG_MIN;
		for(int i = 1; i<=n; i++)
			maxn = max(maxn, a[i]);
		printf("%lld", maxn);
		return 0;
	}
	if(m==n)
	{
		int ans = a[1];
		for(int i = 2; i<=n; i++)
			ans&=a[i];
		printf("%lld", ans);
		return 0;
	}
	if(m==2)
	{
		int maxn = LONG_LONG_MIN;
		for(int l = 1; l<n; l++)
		{
			for(int r = l+1; r<=n; r++)
				maxn = max(maxn, a[l]&a[r]);
		}
		printf("%lld", maxn);
		return 0;
	}
	if(m==n-1)
	{
		int and_sum = a[1];
		for(int i = 2; i<=n; i++)
			and_sum&=a[i];
		int maxn = LONG_LONG_MIN;
		for(int i = 1; i<=n; i++)
			maxn = max(maxn, and_sum^a[i]);
		printf("%lld", maxn);
		return 0;
	}
	if(n<=20)
	{
		
	}
    return 0;
}
