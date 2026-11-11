#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, a[N], m, s[N], u[N];
int main()
{ 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	//for (int i = 1; i <= n; i)
	int ans = 1;
	long long num = a[2] - a[1] + a[2];
	for (int l = 1, r = 2; l <= n; ++l)
	{
		num -= a[r] - a[l - 1];
		while((num + (r - l + 1) * (a[r + 1] - a[r])) <= m && r < n)
		{
			++r;
			num += (r - l) * (a[r] - a[r - 1]);
			//cout << l << ' ' << r << ' ' << num << '\n';
		}
		ans = max(ans, r - l + 1);
		if (r == n) break;
	}
	cout << ans;
}
