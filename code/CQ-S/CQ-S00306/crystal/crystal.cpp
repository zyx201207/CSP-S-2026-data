#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
ll a[N] , sum[N] , b[N];
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n , m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> b[i];
	sort(b + 1 , b + n + 1);
	for(int i = 2;i <= n;i++) a[i - 1] = b[i] - b[i - 1];
	for(int i = 1;i < n;i++) sum[i] = sum[i - 1] + a[i];
	int x = 1 , y = 1 , ans = -1;
	ll num = 0;
	while(x < n and y < n)
	{
		num += a[y] * (y - x + 1);
		while(num > m)
		{
			num -= (sum[y] - sum[x - 1]);
			x++;
		}
		ans = max(y - x + 1 , ans);
		y++;
	}
	cout << ans + 1;
	return 0;
}

