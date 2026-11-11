#include<bits/stdc++.h>
#define N 500010
#define LL long long
using namespace std;

int n, ans;
LL m, a[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = 0;
	LL sum = 0;
	
	while(r < n)
	{
		if(a[r + 1] * (r - l + 2) - (sum + a[r + 1]) > m)
		{
			sum -= a[l];
			l++;
		}
		else
		{
			ans = max(ans, r - l + 2);
			sum += a[r + 1];
			r++;
		}
	}
	printf("%d", ans);
	return 0;
}