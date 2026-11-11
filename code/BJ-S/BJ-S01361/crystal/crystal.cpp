#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500010;
long long a[N], s[N];

int ans(int n, long long m)
{
	int l = 1, r = n, mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (a[n] * (n - mid) - (s[n - 1] - s[mid - 1]) > m) l = mid + 1;
		else r = mid;
	}
	return n - l + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	s[0] = 0;
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int maxans = 1;
	for (int i = 1; i <= n; i++) maxans = max(maxans, ans(i, m));
	cout << maxans << endl;
	return 0;
}