#include <iostream>
using namespace std;

long long n, a[200005], ans;
char c[200005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i] >> c[i];
	long long l = 1, r = n;
	while (l < r)
	{
		long long minn = min(a[l], a[r]);
		if (c[l] != c[r]) ans += minn;
		a[l] -= minn, a[r] -= minn;
		if (!a[l]) ++l;
		if (!a[r]) --r;
	}
	cout << ans << '\n';
	return 0;
}