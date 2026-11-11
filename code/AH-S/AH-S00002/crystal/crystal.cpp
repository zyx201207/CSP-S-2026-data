#include <bits/stdc++.h>
using namespace std;
#define int long long 
int ma[20][500001],sum[500001],a[500001],n,m,lg[500001];
namespace DoubleQlzn 
{
	int query(int l,int r)
	{
		int k = lg[r - l + 1];
		return max(ma[k][l],ma[k][r - (1 << k) + 1]);
	}
	int check(int x)
	{
		for (int i = 1;i + x - 1 <= n;i++)
		{
			int ma = query(i,i + x - 1);
			int s = sum[i + x - 1] - sum[i - 1];
			int now = ma * x - s;
			if (now <= m) return 1;
		}
		return 0;
	}
	void solve()
	{
		cin >> n >> m;
		for (int i = 2;i <= n;i++) lg[i] = lg[i >> 1] + 1;
		for (int i = 1;i <= n;i++) 
		{
			cin >> a[i];
		}
		sort(a + 1,a + n + 1);
		for (int i = 1;i <= n;i++)
		{
			ma[0][i] = a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		for (int j = 1;j <= 19;j++)
		{
			for (int i = 1;i <= n;i++) 
			{
				ma[j][i] = max(ma[j - 1][i],ma[j - 1][i + (1 << (j - 1))]);
			}
		}
		int l = 1,r = n,mid,ans;
		while (l <= r)
		{
			mid = (l + r) >> 1;
			if (check(mid)) l = mid + 1,ans = mid;
			else r = mid - 1;
		}
		cout << ans << '\n';
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T = 1;
	while (T--) DoubleQlzn::solve();
	return 0;
}
