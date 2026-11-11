#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 7;

int n;

ll m;

ll a[N];

int ans = 1;

bool check(int l, int r, ll x)
{
	ll sum = a[r] - a[l - 1];
	
	ll p = 1LL * (r - l + 1) * x;
	
	ll diff = p - sum;
	
//	cout << l << ' ' << r << ' ' << diff << '\n';
	
	return (diff <= m);
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	cin.tie(0) -> ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for(int i(1); i <= n; ++i)
		cin >> a[i];
		
	sort(a + 1, a + n + 1); 
	
	for(int i(1); i <= n; ++i)
		a[i] += a[i - 1];
		
	for(int i(2); i <= n; ++i)
	{
		int l(1), r(i - 1);
		
		int Max(0);
		
		while(l <= r)
		{
			int mid(l + r >> 1);
			
			if(check(mid, i - 1, a[i] - a[i - 1]))(r = (Max = mid) - 1);
			else l = mid + 1;
		}
		
//		cout << i << ' ' << Max << '\n'; 
		
		ans = max(i - Max + 1, ans);
	}
	
	cout << ans << '\n';
	
	return 0;	
} 
