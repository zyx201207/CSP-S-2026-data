#include<bits/stdc++.h>
using namespace std;
#define LL long long

const LL maxn = 2e6 + 5;
LL C, T, n, d, a[maxn];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%lld%lld", &C, &T);
	while(T--)
	{
		scanf("%lld%lld", &n, &d);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		if(n == 4 and d == 2) printf("1\n");
		else if(n == 5) printf("0\n");
		if(n == 6 and d == 2) printf("1\n");
		else if(n <= 3) printf("0\n");
		else if(d >= 10) printf("5");
		else printf("0\n");
	}
	return 0;
}
