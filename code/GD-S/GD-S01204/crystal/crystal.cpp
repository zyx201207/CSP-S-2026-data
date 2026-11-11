#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 5;

ll a[N], d[N], pre[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n; ll m;
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++)
		cin >> a[i];
		
	sort(a + 1, a + n + 1);
	
	for(int i = 1;i <= n;i++)
		d[i] = a[i] - a[i - 1];
	
	d[1] = 0;
	//for(int i = 1;i <= n;i++)
		//pre[i] = pre[i - 1] + d[i];
		
	function<ll(int, int)> gets = [&](int l, int r) -> ll
	{
		ll sum = 0, s = l + 1;
		for(int i = s + 1;i <= r;i++)
			sum += d[i] * (i - s);
		return sum;		
	};
	
	int ans = 0;
	int l = 0, r = 1;
	while(r <= n)
	{
		//cout << l << " " << r << " " << sum << "\n";
		ll sum = gets(l, r);
		if(sum <= m)
		{
			ans = max(ans, r - l);
			++r;
		}
		else ++l;
	}
	
	cout << ans;
	
	return 0;
}
