#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[100005];
long long mx = LLONG_MIN;

void dfs(long long step, long long ad, long long now)
{
	if (step == m)
	{
		mx = max(mx, ad);
		return;
	}
	for (int i = now + 1; i <= n; i++)
	{
		dfs(step + 1, ad & a[i], i);
	}
}	

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		dfs(1, a[i], i);
	}
	cout << mx << "\n";
	return 0;	
}
