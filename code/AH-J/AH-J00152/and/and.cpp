#include<bits/stdc++.h>
using namespace std;
int n, m, visited[200005];
unsigned long long a[200005], ans;
void f(int s, int t, unsigned long long A)
{
	if(t == m)
	{
		ans = max(A, ans);
		return;
	}
	if(A == -1)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				visited[i] = 1, visited[j] = 1;
				f(j, 2, (a[i] & a[j]));
				visited[i] = 0, visited[j] = 0;
			}
		}
	}
	else
	{
		for(int i = s + 1; i <= n; i++)
		{	
			if(visited[i] == 0) 
			{
				visited[i] = 1;
				f(i, t + 1, (a[i] & A));
				visited[i] = 0;
			}
		}
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i]; 
	sort(a + 1, a + 1 + n);
	if(m == 1)
	{
		cout << a[n];
		return 0; 
	}
//	if(m == 1) cout << a[n];
//	ans = a[n];
//	for(int i = n - 1; i > n - m; i--)
//	{
//		ans &= a[i];
//		cout << ans << " "; 
//	}
	f(0, 0, -1);
	cout << ans;
	return 0;
}
