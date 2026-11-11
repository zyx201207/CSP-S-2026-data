#include <bits/stdc++.h>
#define rep1(i,a,b) for (int i = a;i <= b;i++)
#define int long long
using namespace std;
/*
枚举最后用哪个值合成大水晶
瞎搞即可 
*/
const int N = 5e5 + 10;
int n,m,ans;
int a[N],sum[N];
int query(int l,int r) { return sum[r] - sum[l - 1]; }
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	rep1(i,1,n)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	rep1(i,1,n)
		sum[i] = sum[i - 1] + a[i];
	rep1(i,1,n)
	{
		int l = 1;
		int r = i;
		int ns = 0;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (query(mid,i) + m >= a[i] * (i - mid + 1))
			{
				ns = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		ans = max(ans,i - ns + 1);
	}
	cout << ans;
}
