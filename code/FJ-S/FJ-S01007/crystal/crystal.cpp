#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],sum[500005],l,r,mid,ans,cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort (a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
	{
		sum[i] = sum[i - 1] + a[i];
		l = 1;r = i,mid = 0;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (a[i] * mid <= sum[i] - sum[i - mid - 1] + m)
				l = mid + 1,cnt = mid;
			else
				r = mid - 1;
		}
		ans = max(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}
