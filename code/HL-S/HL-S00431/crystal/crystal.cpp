#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long m;
long long a[500010];
long long b[500010];
int ans;

int main()
{
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d %lld", &n, &m);
	for(int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
	
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; i ++ ) b[i] = b[i - 1] + a[i];
	
	int l = 1, r = 1;
	
	while(l <= r && r <= n)
	{
		while(l != r && b[l - 1] - b[r - 1] + a[r] * (r - l) > m) l ++ ;
		ans = max(ans, r - l + 1);
		r ++ ;
	}
	
	printf("%d", ans);
	
	return 0;
}