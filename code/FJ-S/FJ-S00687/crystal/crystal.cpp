#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n;
ll m, a[N], sum[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
	int mx = 0;
	
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i, ans = 1;
		while (l <= r && l >= 1 && r <= i)
		{
//			cout << l << ' ' << r << '\n';
			int mid = (l + r) >> 1;
			if (a[i]*(i-mid+1) - (sum[i]-sum[mid-1]) <= m)
			{
				r = mid - 1;
				ans = i - mid + 1;
			}
			else l = mid+1;
		}
//		cout << mx << '\n';
		mx = max(mx, ans);
	}
	
	cout << mx;
	return 0;
 } 	
