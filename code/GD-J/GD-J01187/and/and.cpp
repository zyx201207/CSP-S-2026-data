#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

ll a[N]; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	freopen("and3.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	if(m == 1) cout << a[max_element(a + 1, a + n + 1) - a];
	else if(m == n)
	{
		ll ans = a[1];
		for(int i = 2;i <= n;i++)
			ans and_eq a[i];
		cout << ans;
	}
	else if(m == 2)
	{
		ll ans = -4e18;
		for(int i = 1;i < n;i++)
		{
			for(int j = i + 1;j <= n;j++)
				ans = max(ans, a[i] & a[j]);
		}
		cout << ans;
	}
	else
	{
		sort(a + 1, a + n + 1, greater<ll>());
		ll ans = a[1];
		for(int i = 2;i <= m;i++)
			ans and_eq a[i];
			
		cout << ans;
	}
	
	
	return 0;
}
