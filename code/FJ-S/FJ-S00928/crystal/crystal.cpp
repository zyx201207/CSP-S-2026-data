#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 5e5 + 50;
ll n, m, ans = 1, val = 0, a[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll l = 1, r = 1;
	while(r < n)
	{
		r++;
		val += (r - l)*(a[r] - a[r - 1]);
		while(l < r && val > m)
		{
			l++;
			val -= (a[r] - a[l - 1]);
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << "\n";
	return 0;	
}
