#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], mx = -1, ans, mx_8 = -1, pi[21], ans_13, p16 = 1, num2, num3;
//                                 8-10       13       14 15           13
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	pi[0] = 1;
	for (int i = 1; i <= 20; i++)
	{
		pi[i] = 2 * pi[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx = max(a[i], mx);
		if(a[i] == 2) num2++;
		if(a[i] == 3) num3++;
	}
	if(mx >= 4)
	{
		p16 = 0;
	}
	ans = a[1];
	//6
	if(m == 1)
	{
		cout << mx;
		return 0;
	}
	//7
	else if(m == n)
	{
		for (int i = 1; i <= n; i++)
		{
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	//8-10
	if(m == 2 && n <= 2000)
	{ 
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n && j != i; j++)
			{
				mx_8 = max(mx_8, (a[i] & a[j]));
			}
		}
		cout << mx_8;
		return 0;
	}
	//16-17
	if(p16 == 1)
	{
		if(num3 >= m)
		{
			cout << 3;
			return 0;
		}
		else if(num2 + num3 >= m)
		{
			cout << 2;
			return 0;
		}
		else if(n - num2 > m)
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
		
	}
	//13 A 14-15 B
	else
	{
		sort(a + 1, a + n + 1);
		ans_13 = a[n];
		for (int i = n; i >= n - m + 1; i--)
		{
			ans_13 &= a[i];
		}
		cout << ans_13;
		return 0;
	}
	
}
