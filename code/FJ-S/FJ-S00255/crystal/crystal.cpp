#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 5e5 + 10;
int n, ans;
LL m, a[N], sum[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for(int i = 1;i <= n; ++ i)
		scanf("%lld", &a[i]); 
		
	sort(a + 1, a + n + 1);
		
	for(int i = 1;i <= n; ++ i)
		sum[i] = sum[i - 1] + a[i];
	
	int p = 1;
	for(int i = 1;i <= n; ++ i)
	{
		while(a[i] * (i - p + 1) - (sum[i] - sum[p - 1]) > m)
			p ++;
		ans = max(ans, i - p + 1);
	} 
	printf("%d", ans);
	return 0; 
}
