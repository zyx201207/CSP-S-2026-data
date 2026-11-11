#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], ans;
bool ch[N];
void dfs(int i, int x)
{
	if(i > n && x != m)return;
	if(i > n && x == m)
	{
		int sum = -1;
		for(int i = 1; i <= n; i++)
		{
//			cout << ch[i] << ' ';
			if(ch[i])
			{
				if(sum == -1)sum = a[i];
				else sum &= a[i];
			}
		}
		cout << sum << endl;
		ans = max(ans, sum);
		return;
	}
//	cout << i << ' ' << x << endl;
	dfs(i + 1, x);
	ch[i] = 1;
	dfs(i + 1, x + 1);
	ch[i] = 0;
}


int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	if(m == 1)
	{
		int maxx = 0;
		for(int i = 1; i <= n; i++)
		{
			maxx = max(maxx, a[i]);
		}
		cout << maxx;
		return 0;
	}
	if(m == n)
	{
		ans = a[1];
		for(int i = 2; i <= n; i++)
		{
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if(m == 2)
	{
		for(int i = 1; i < n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(n <= 20)
	{
		dfs(1, 0);
		cout << ans;
		return 0;
	}
	return 0;
}
