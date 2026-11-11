#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

const int N = 5e5 + 10;
int n, m, ans;
int a[N], d[N], sum[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 2; i <= n; i++) 
		d[i] = a[i] - a[i - 1];
	reverse(d + 1, d + 1 + n);
	for(int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + d[i];
	
	int r = 0, now = 0;
	for(int l = 1; l < n; l++)
	{
		while(r + 1 < n && now + sum[r + 1] - sum[l - 1] <= m)
			r++, now += sum[r] - sum[l - 1];
		ans = max(ans, r - l + 2);
		now -= (r - l + 1) * d[l];
	}
	cout << ans;
	return 0;
} 

/*
¿ªlong long
Ë«Ö¸Õë 
*/
