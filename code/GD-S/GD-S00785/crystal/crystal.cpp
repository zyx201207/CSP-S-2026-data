#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int n, mx = 1;
ll m, a[500005], pre[500005];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for (int i = 2; i <= n; i++)
	{
		int l = 1, r = i - 1, mid, k;
		if (a[i - 1] + m < a[i]) continue;
		while (l <= r)
		{
			mid = (l + r) >> 1;
			if ((i - mid) * a[i] - (pre[i - 1] - pre[mid - 1]) <= m)
			{
				r = mid - 1;
				k = mid;
			}
			else l = mid + 1;
		}
		mx = max(mx, i - k + 1);
	}
	cout << mx;
	return 0;
}
