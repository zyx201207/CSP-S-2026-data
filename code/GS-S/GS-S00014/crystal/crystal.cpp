#include <bits/stdc++.h>
using namespace std;

namespace ljw
{
	typedef long long ll;
	
	const int N = 5e5 + 10;
	ll a[N], s[N];
	
	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		
		freopen("crystal.in", "r", stdin);
		freopen("crystal.out", "w", stdout);

//		freopen("crystal4.in", "r", stdin);
//		freopen("crystal4.out", "w", stdout);
		
		ll n, m;
		cin >> n >> m;
		
		for (int i = 1; i <= n; i++)
			cin >> a[i];
			
		sort(a + 1, a + n + 1);
		
		for (int i = 1; i <= n; i++)
			s[i] = s[i - 1] + a[i];
		
		int res = 0;	
		for (int i = n; i; i--)
		{
//			ll now = a[i] * (i - 1) - s[i - 1];

			int l = 1, r = i;
			while (l < r)
			{
				int mid = (l + r) >> 1;
				
				if (a[i] * (i - mid) - (s[i - 1] - s[mid - 1]) <= m)
					r = mid;
				else
					l = mid + 1;
			}
			
			if (a[i] * (i - l) - (s[i - 1] - s[l - 1]) <= m)
				res = max(res, i - l + 1);
		}
		
		cout << res << '\n';
		
		
		
		return 0;
	}
}

int main()
{
	return ljw::main();
}
/*
k - a[i]

p - a[i]

k - a[i] - (k - p)

sum - (k - p) * len - ?;		
*/
