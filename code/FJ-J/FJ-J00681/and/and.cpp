#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005], f[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1, a+n+1);
	
	if (m == 1)
	{
		cout << a[n];
		return 0;
	}
	else if (m == n)
	{
		int sum = a[1];
		for (int i=1;i<=m;i++) sum &= a[i];
		cout << sum;
		return 0;
	}
	else if (m == 2)
	{
		f[1] = a[1];
		f[2] = max(a[1], a[2]);
		for (int i=3;i<=n;i++) f[i] = max(f[i-1] & a[i], f[i-1]);
		cout << f[n];
		return 0;
	}
	else
	{
		int ans = a[n];
		for (int i=n-1;i>=n-m+1;i--) ans &= a[i];
		cout << ans;
	}
	return 0;
}
