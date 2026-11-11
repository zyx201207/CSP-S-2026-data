#include <bits/stdc++.h>
using namespace std;

int a[200005], n, m;
int b[200005];
bool vis[200005];

bool cmp(int x, int y)
{
	return x > y;
}

bool checkA()
{
	for(int i = 1; i <= n; i++)
	{
		if(int(log2(a[i] + 1)) != log2(a[i] + 1))
		{
			return false;
		}
	}
	return true;
}

bool checkB()
{
	if(int(log2(n)) != log2(n))
	{
		return false;
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != i - 1)
		{
			return false;
		}
	}
	return true;
} 

bool checkC()
{
	long long cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		cnt += a[i];
	}
	return cnt <= 4;
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(m == n - 1)
	{
		sort(a + 1, a + n + 1, cmp);
		int ans = a[1];
		for(int i = 1; i < n; i++)
		{
			ans = ans & a[i];
		}
		cout << ans;
	}
	else if(checkA())
	{
		sort(a + 1, a + n + 1, cmp);
		cout << a[m];
	}
	else if(checkB())
	{
		sort(a + 1, a + n + 1, cmp);
		int ans = a[1];
		for(int i = 1; i <= m; i++)
		{
			ans = ans & a[i];
		}
		cout << ans;
	}
	else if(checkC())
	{
		int c[200005];
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i])
			{
				c[++sum] = a[i];
			}
		}
		sort(c + 1, c + sum + 1, cmp);
		if(m > sum)
		{
			cout << 0;
		}
		else
		{
			int ans = c[1];
			for(int i = 1; i <= m; i++)
			{
				ans = ans & c[i];
			}
			cout << ans;
		}
	}
	else if(n <= 2000)
	{
		sort(a + 1, a + n + 1, cmp);
		b[1] = a[1];
		vis[1] = true;
		for(int i = 2; i <= n; i++)
		{
			int maxn = 0, maxid;
			for(int j = 1; j <= n; j++)
			{
				if((a[j] and b[i - 1]) > (maxn and b[i - 1]) && !vis[j])
				{
					maxn = a[j];
					maxid = j;
				}
			}
			b[i] = maxn;
			vis[maxid] = true;
		}
		int ans = b[1];
		for(int i = 1; i <= m; i++)
		{
			ans = ans & b[i];
		}
		cout << ans;
	}
	return 0;
}
