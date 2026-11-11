#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read()
{
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
const int N = 2e5 + 5;
int n , m;
int a[N];
bool cmp(int x , int y)
{
	return x > y;
}

signed main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	n = read() , m = read();
	int sum = 0 , num = 1;
	for(int i = 1;i <= n; ++ i)
	{
		a[i] = read();
		if(__lg(a[i] + 1) % 1 == 0)
			sum ++;
		if(a[i] == a[i - 1])
			num ++;
	}
	sort(a + 1 , a + n + 1 , cmp);
	if(sum == n)
	{
		int p = a[1];
		for(int i = 2;i <= m; ++ i)
		{
			p &= a[i];
		}
		cout << p;
		return 0;
	}
	if(m == 1)
	{
		cout << a[1];
		return 0;
	}
	if(m == n)
	{
		int p = a[1];
		for(int i = 2;i <= n; ++ i)
		{
			p &= a[i];
		}
		cout << p;
		return 0;
	}
	if(m == 2)
	{
		int ans = -0x3f3f3f3f;
		for(int i = 1;i <= n; ++ i)
		{
			int p = a[i];
			for(int j = i + 1;j <= n; ++ j)
			{
				if(j == i + 1)
					p &= a[j];
				else
					p = max(p , a[i] & a[j]);
			}
			ans = max(ans , p);
		}
		cout << ans;
	}
	if(num == n)
	{
		int p = -1 , tot = 0;
		for(int i = 1;i <= n; ++ i)
		{
			if(__lg(a[i] + 1) % 1 == 0 && a[i] >= 0)
			{
				if(p == -1)
					p = a[i] , ++ tot , a[i] = -1;
				else
				{
					p &= a[i];
					a[i] = -1;
					++ tot;
				}
			}
			if(tot == m)
			{
				cout << p;
				return 0;
			}
		}
		for(int i = 1;i <= n; ++ i)
		{
			if(tot == m)
			{
				cout << p;
				return 0;
			}
			if(a[i] > 0)
			{
				tot ++;
				p &= a[i];
			}
		}
		cout << p;
		return 0;
	}
	if(m == n - 1)
	{
		int p = a[1];
		for(int i = 2;i < n; ++ i)
		{
			p &= a[i];
		}
		cout << p;
	}
	return 0;
}
