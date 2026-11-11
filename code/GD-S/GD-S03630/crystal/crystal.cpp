#include <bits/stdc++.h>
using namespace std;
int main()
{
	/*
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	*/
	int n , m , ans = 0 , ans2 = 0 , maxn = -100000 , v = 100000 , f = -100000 , a[1000000];
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		v = min(a[i] , v);
	}
	for (int i = 1;i <= n;i++)
	{
		++ans;
		ans2 += a[i];
		f = max(a[i] , f);
		if ((ans2 + m) % ans == 0)
		{
			if (v + m >= f)
			{
				maxn = ans;
			}
		}
	}
	cout << maxn;
} 
