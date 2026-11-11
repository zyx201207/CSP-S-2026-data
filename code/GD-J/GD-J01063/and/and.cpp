#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, m, ans;
int a[N], s1[N], s2[N];
void dfs(int u, int s, int z)
{
	if(u > n)
	{
		ans = max(ans, z);
		return;
	}
	if(z != 0 && z < ans) return ;
	if(s + (n-u+1) < m) return ;
	if(s + (n-u) >= m) dfs(u+1, s, z);
	if(s < m)
	{
		if(s == 0) dfs(u+1, s+1, a[u]);
		else dfs(u+1, s+1, z & a[u]);
	}
}
bool A = 1, B = 1;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	if(log2(n) != int(log2(n))) B = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != i-1) B = 0;
		if(log2(a[i]+1) != int(log2(a[i]+1))) A = 0;
	}
	if(n <= 0)
	{
		dfs(1, 0, 0);
		cout << ans;
	}
	else if(m == 1)
	{
		int mx = 0;
		for(int i = 1; i <= n; i++)
		{
			mx = max(mx, a[i]);
		}
		cout << mx;
	}
	else if(m == n)
	{
		int sum = a[1];
		for(int i = 1; i <= n; i++)
		{
			sum &= a[i];
		}
		cout << sum;
	}
	else if(A)
	{
		sort(a+1, a+n+1);
		int sum = a[n];
		for(int i = n; i >= n-m+1; i--)
		{
			sum &= a[i];
		}
		cout << sum;
	}
	else if(m == n-1)
	{
		s1[1] = a[1];
		s2[n] = a[n];
		for(int i = 2; i <= n; i++)
		{
			s1[i] = s1[i-1] & a[i];
		}
		for(int i = n-1; i >= 1; i --)
		{
			s2[i] = s2[i+1] & a[i];
		}
		int mx = (s1[n-1], s2[2]);
		for(int i = 2; i <= n-1; i++)
		{
			mx = max(mx, s1[i-1] & s2[i+1]);
		}
		cout << mx;
	}
	else if(m == 2)
	{
		dfs(1, 0, 0);
		cout << ans;
	}
	else if(B)
	{
		cout << n - m;
	}
	return 0;
}
