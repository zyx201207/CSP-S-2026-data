#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;

int n, m;
long long res = -1;
long long a[N]; 
bool vis[N];

void solve(int tot, long long sum)
{
	if (tot == m)
	{
		res = max(res, sum);
		return;	
	} 
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				vis[i] = true;
				if (tot == 0) solve(1, a[i]);
				else solve (tot + 1, sum & a[i]); 
				vis[i] = false;
			}
		}
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	if (m == 1)
	{
		sort(a + 1, a + n + 1);
		cout << a[n];
		return 0; 
	}
	else if (m == 2)
	{
		long long ans = -1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	else if (m == n)
	{
		long long ans = a[1];
		for (int i = 2; i <= n; i++) ans &= a[i];
		cout << ans;
		return 0;	
	}
	else
	{
		solve(0, 0);
		cout << res;
		return 0;
	}
}
