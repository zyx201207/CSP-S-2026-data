#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
const int N = 5e5 + 114;
ll a[N];
int ansn;



int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if(m == 0)
	{
		cout << 1;
		return 0;
	}
	bool A = 1, B = 1, C = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != i)
		{
			A = 0;
		}
		if(i >= 3)
		{
			if(a[i] - a[i - 1] != a[2] - a[1])
			{
				B = 0;
			}
		}
		if(i >= 2)
		{
			if(a[i] - a[i - 1] > m)
			{
				C = 0;
			}
		}
	}
	if(A)
	{
		ll ans[N];
		ans[1] = 0;
		for(int i = 2; i <= n; i++)
		{
			ans[i] = ans[i - 1] + (i - 1) * (a[i] - a[i - 1]);
		}
		int maxn = 0;
		for(int i = 1; i <= n; i++)
		{
			if(m < ans[i])
			{
				break;
			}
			maxn++;
		}
		if(maxn == 0)
		{
			cout << n;
		}
		else
		{
			cout << maxn;
		}
	}
	else if(B)
	{
		ll ans[N];
		ans[1] = 0;
		for(int i = 2; i <= n; i++)
		{
			ans[i] = ans[i - 1] + (i - 1) * (a[i] - a[i - 1]);
		}
		int maxn = 0;
		for(int i = 1; i <= n; i++)
		{
			if(m < ans[i])
			{
				break;
			}
			maxn++;
		}
		if(maxn == 0)
		{
			cout << n;
		}
		else
		{
			cout << maxn;
		}
	}
	else if(C)
	{
		ll ans[N];
		sort(a + 1, a + n + 1);
		ans[1] = 0;
		for(int i = 2; i <= n; i++)
		{
			ans[i] = ans[i - 1] + (i - 1) * (a[i] - a[i - 1]);
		}
		int maxn = 0;
		for(int i = 1; i <= n; i++)
		{
			if(m < ans[i])
			{
				break;
			}
			maxn++;
		}
		if(maxn == 0)
		{
			cout << n;
		}
		else
		{
			cout << maxn;
		}
	}
	else
	{
		cout << n;
	}
	return 0;
} 
