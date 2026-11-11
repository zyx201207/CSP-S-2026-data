#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, ans(0);
struct code
{
	ll l;
	char c;
} a[200005];

void f()
{
	ll x = 1, y = n, tmp(0);
	while (x < y)
	{
		if (a[x].c != a[y].c)
		{
			if (a[x].l > a[y].l)
			{
				ans += a[y].l;
				a[x].l -= a[y].l;
				y--;
			}
			else if (a[x].l < a[y].l)
			{
				ans += a[x].l;	
				a[y].l -= a[x].l;
				x++; 
			}
			else
			{
				ans += a[x].l;
				x++;
				y--;
			}
		}
		else
		{
			if (a[x].l > a[y].l)
			{
				a[x].l -= a[y].l;
				y--;
			}
			else if (a[x].l < a[y].l)
			{	
				a[y].l -= a[x].l;
				x++; 
			}
			else
			{
				x++;
				y--;
			}
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].l >> a[i].c;
	}
	f();
	cout << ans;
	return 0;
} 


/*

3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
