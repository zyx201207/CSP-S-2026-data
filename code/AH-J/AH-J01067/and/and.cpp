#include <bits/stdc++.h>
#define int long long
#define N 200010
using namespace std;

int n, m;
int a[N];
int answer = 0;

void dfs(int dep, int from, int sum)
{
	if (dep == m) {answer = max(answer, sum); return;}
	for (int i = from + 1; i <= n; i++)
		dfs(dep + 1, i, sum & a[i]);
}

void solve_task11_12()
{
	int cnt;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1) cnt = a[2];
		else cnt = a[1];
		for (int j = 1; j <= n; j++)
			if (j != i)
				cnt &= a[j];
		answer = max(answer, cnt);
	}
}

signed main()
{
	freopen("and.in",  "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == m)
	{
		answer = a[1];
		for (int i = 2; i <= n; i++)
			answer &= a[i];
		cout << answer;
		return 0;
	}
	else if (n == m + 1)
	{
		solve_task11_12();
		cout << answer;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		dfs(1, i, a[i]);
	cout << answer;
	return 0;
}
