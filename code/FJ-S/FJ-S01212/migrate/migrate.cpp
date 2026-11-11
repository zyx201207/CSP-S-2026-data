#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e6 + 10;
int C, t, n, d, a[N], cnt[N], ex, mn, ans;
void dfs(int now, int cnt)
{
	if(a[now] > a[ex])
		return ;
	if(now == ex)
	{
		if(mn > cnt)
		{
//			cout << cnt << endl;
			ans = 1;
			mn = cnt;
		}
		else if(mn == cnt)
			ans++;
		return ;
	}
	for(int i = now + 1; i <= n; i++)
	{
		if(a[i] - a[now] <= d)
			dfs(i, cnt + 1);
		else
			break;
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int res = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				mn = 1e9;
				ex = j;
				dfs(i, 0);
				if(ans == 2)
					res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}
