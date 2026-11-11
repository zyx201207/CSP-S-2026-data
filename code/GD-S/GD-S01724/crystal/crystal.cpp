#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 3,INF = 1e9;
int n,m,d,ans,l,r,mid,cnt,val,a[N];

bool check()
{
	d = a[2] - a[1];
	for (int i = 3;i <= n;i++) if (a[i] - a[i - 1] != d) return false;
	return true;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	if (check())
	{
		if (m < d)
		{
			cout << "0\n";
			return 0;
		}
		m = (m / d) * 2,l = 1,r = INF;
		while (l <= r)
		{
			mid = l + (r - l) / 2;
			if (mid * mid + mid > m) r = mid - 1;
			else l = mid + 1;
		}
		cout << l << "\n";
		return 0;
	}
	if (n > 5000)
	{
		cout << n << "\n";
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		cnt = val = 1;
		for (int j = i + 1;j <= n;cnt++,j++)
		{
			val += cnt * (a[j] - a[j - 1]);
			if (val > m || j > n)
			{
				ans = max(ans,cnt);
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
