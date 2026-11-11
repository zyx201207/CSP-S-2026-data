#include <bits/stdc++.h>
using namespace std;

int dfs(int s, int j)
{
	int cnt = 0;
	if(s == 0)
	{
		return 1;
	}
	if(s < 0)
	{
		return 0;
	}
	for(int i = 1; i <= j; i++)
	{
		cnt += dfs(s - i, j);
	}
	return cnt;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		int n, d;
		cin >> n >> d;
		int gc;
		int a, b;
		cin >> b >> a;
		for(int i = 3; i <= n; i++)
		{
			int c;
			cin >> c;
		}
		gc = a - b;
		if(d < gc)
		{
			cout << 0;
			continue;
		}
		int j = d / gc;
		int ans = 0;
		for(int i = 2; i <= n; i++)
		{
			ans += dfs(i, min(i, j));
		}
		cout << ans << endl;
	}
} 
