#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5000005];
signed main()
{
	
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		
			ans += a[i];
		
	}
	cout << ans;
	return 0;
 } 
