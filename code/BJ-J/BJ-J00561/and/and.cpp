#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a[200200], ans, pw[32] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		for(int j = 0; 
	}
	sort(a + 1, a + n + 1);
	for(int i = 0; i < m; i++) {
		int j = n - i;
		ans &= a[j];
	}
	cout << ans << '\n';
	
    return 0;
}
