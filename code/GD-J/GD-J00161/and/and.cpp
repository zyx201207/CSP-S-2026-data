#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define ll long long
int n, m, a[N];
ll ans, mx, sum;
void dfs(int i, int cnt, int k)
{
	if(m - k > n - i + 1) return;
	if(i > n)
	{
		if(k == m) ans = max(ans, (ll)cnt);
		return;
	}
	if(k == 0)
	{
		dfs(i + 1, a[i], k + 1);
		dfs(i + 1, cnt, k);
	} 
	else
	{
		dfs(i + 1, (cnt & a[i]), k + 1);
		dfs(i + 1, cnt, k);
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx = max(mx, (ll)a[i]);
	}
	sum = a[1];
	for(int i = 2; i <= n; i++) sum = (sum & a[i]);
	if(m == 1)
	{
		cout << mx << "\n";
		return 0;
	}
	else if(m == n)
	{
		cout << sum << "\n";
		return 0; 
	}
	dfs(1, 0, 0);
	cout << ans << "\n";
	return 0;
}
