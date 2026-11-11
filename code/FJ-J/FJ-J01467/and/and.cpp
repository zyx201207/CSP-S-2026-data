#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], dp[2010][2010], m; // 处理到i,正好选了j个数 的最大值 
int vis[2010], mx, flagA;
void dfs(int now, int cnt)
{
	if(now == n + 1 and cnt != m)
		return ;
	if(cnt == m)
	{
		int sum = 0, flag = 0;
		for(int i = 1; i <= n; i++)
		{
			if(vis[i] == 1 and flag == 0)
				sum = a[i], flag = 1;
			else if(vis[i] == 1)
				sum &= a[i];
		}
		mx = max(mx, sum);
		return ;
	}
	vis[now] = 1;
	dfs(now + 1, cnt + 1);
	vis[now] = 0;
	dfs(now + 1, cnt);
}
void solve1()
{
	dfs(1, 0);
	cout << mx << endl;
}
void solve2()
{
	if(m == 1)
	{
		for(int i = 1; i <= n; i++)
			mx = max(mx, a[i]);
		cout << mx << endl;
	}
	else if(m == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
				mx = max(mx, (a[i] & a[j]));
		}
		cout << mx << endl;
	}
	else if(m == n)
	{
		int sum = a[1];
		for(int i = 1; i <= n; i++)
			sum &= a[i];
		cout << sum << endl;
	}
}
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(pow(2, log2(a[i] + 2)) != a[i])
			flagA = 1;
	}
	if(!flagA)
	{
		sort(a + 1, a + n + 1, cmp);
		int sum = a[1];
		for(int i = 1; i <= m; i++)
			sum &= a[i];
		cout << sum << endl;
	}
	else if(n <= 20)
		solve1();
	else if(n <= 2000)
		solve2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 3
31 3 1 15 7
*/
