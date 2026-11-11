#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

const int MAXN = 5e5 + 7;

ll n, m;
ll a[MAXN];
ll p1[MAXN], p2[MAXN];

ll ptr1, ptr2;
ll ans = 1;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	std::sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++)
	{
		p1[i] = a[n] - a[i];
		p2[i] = p2[i - 1] + p1[i];
	}
	
	/*
	for (int i = 1; i <= n; i++) std::cout << p1[i] << ' ';
	std::cout << std::endl;
	for (int i = 1; i <= n; i++) std::cout << p2[i] << ' ';
	std::cout << std::endl;
	*/
	
	ll idx = n;
	ll opcnt = 0;
	for (int i = n; i >= 1; i--)
	{
		if (idx == i) idx--;
		
		while (opcnt <= m && idx > 0)
		{
			ans = std::max(ans, i - idx + 1);
			idx--;
			opcnt += a[i] - a[idx];
		}
		opcnt -= (i - idx) * (a[i] - a[i - 1]);
	}
	
	std::cout << ans;
}
