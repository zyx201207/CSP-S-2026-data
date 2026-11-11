#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long

const int N = 5e5 + 10;
int n,m,a[N],sum[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i ++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		int l = 1,r = i,res = 0;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if ((sum[i] - sum[mid - 1] + m) >= a[i] * (i - mid + 1)) res = mid,r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans,i - res + 1);
	}
	cout << ans << endl;
	return 0;
}
