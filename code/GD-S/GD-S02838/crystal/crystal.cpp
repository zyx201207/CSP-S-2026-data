#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m;
#define int long long
int a[N];
int s[N];
int pre[N];
int ans = 0;

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++) s[i] = a[i] - a[i-1], pre[i] = pre[i-1] + a[i];
	int l = n;
	for(int r = n; r >= 1; r--)
	{
		int sz = r-l;
		int cost = a[r] * sz - pre[r-1] + pre[l-1];
		while(cost <= m && l >= 1)
		{
			ans = max(ans, r-l+1);
//			cout << l << " " << r << endl;
			l--;
			sz++;
			cost = a[r] * sz - pre[r-1] + pre[l-1];
		}
	}
	cout << ans << endl;
}
