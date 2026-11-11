#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e6 + 10;

int c, t, n;
ll d, a[N];

inline bool solve(int l, int r)
{
	ll num = 0, tt = 1;
	for(int i = l + 1; i <= r; ++ i)
	{
		if(num + (a[i] - a[i - 1]) > d) ++ tt, num = 0;
		num += (a[i] - a[i - 1]);
		if(a[i] - a[i - 1] > d) return 0;
	}
	if(tt == r - l + 1 || tt == 1) return 0;
	
	ll ans = 0;
	
//	printf("%lld\n", tt);
	
	for(int i = l + 1; i < r; ++ i)
	{
		ll num1 = 0, tt1 = 1;
		for(int j = l + 1; j <= i; ++ j)
		{
			if(num1 + (a[j] - a[j - 1]) > d) ++ tt1, num1 = 0;
			num1 += (a[j] - a[j - 1]);
		}
		
		ll num2 = 0, tt2 = 1;
		for(int j = i + 1; j <= r; ++ j)
		{
			if(num2 + (a[j] - a[j - 1]) > d) ++ tt2, num2 = 0;
			num2 += (a[j] - a[j - 1]);
		}
		
		if(tt1 + tt2 == tt) 
		{
			++ ans;
//			printf("%lld\n", i);
		}
	}
	
	return ans == 2 ? 1 : 0;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	
	while(t --)
	{
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; ++ i) scanf("%lld", &a[i]);
		
		if(c >= 1 && c <= 6)
		{
			int num = 0;
			
			for(int l = 1; l <= n; ++ l)
			{
				for(int r = l + 1; r <= n; ++ r)
				{
					if(solve(l, r)) 
					{
						++ num;
//						printf("%d %d\n", l, r);
					}
				}
			}
			
			printf("%d\n", num);
		}
		
		else if(c >= 11 && c <= 12)
		{
			ll num = a[2] - a[1], tot = d / num;
			if(tot == 0 || tot == 1 || tot >= n - 1) puts("0");
			else printf("%lld\n", n - 2 * tot + 1);
		}
		
//		if(c >= 13 && c <= 14)
//		{
//			int num = 0;
//			for(int i = 1; i <= n; ++ i) if(a[i] - a[1] <= d && a[n] - a[i] <= d) ++ num;
//			if(num != 2) 
//		}

		else puts("0");
	}
	
	return 0;
}