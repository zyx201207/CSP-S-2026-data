#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
int n, ans;
long long m, a[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	long long sum = 0;
	for (int i = 1, j = 1; i <= n; i++)
	{
		sum += (i - j) * (a[i] - a[i - 1]);
		while (sum > m)
			sum -= a[i] - a[j++];
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
