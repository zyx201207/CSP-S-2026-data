#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long s[500010];
int u[500010];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	u[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		u[i] = u[i - 1];
		while ((long long)(i-u[i]+1)*a[i] - (s[i] - s[u[i] - 1]) > m)
			u[i]++;
	}
	int mx = 0;
	for (int i = 1; i <= n; i++)
		mx = max(mx, i - u[i] + 1);
	cout << mx;
	return 0;
}
