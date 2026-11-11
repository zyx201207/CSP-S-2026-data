#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;

int n, m, a[N], sum[N], ans;

bool chk(int x, int y)
{ return (sum[y] - sum[x - 1] + m >= (y - x + 1) * a[y]); }

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for(int i = n; i >= 1; i--)
	{
		int l = 1, r = i, tmp = 0;
		while(l <= r)
		{
			int mid = l + (r - l) / 2;
			if(chk(mid, i)) tmp = i - mid + 1, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}

/*

15：08 
cnm我是sb cnm我是sb cnm我是sb cnm我是sb cnm我是sb
TM我先算前缀和再排序的sb错误硬控我 20min 
没想到T1如此简单？ 

*/











