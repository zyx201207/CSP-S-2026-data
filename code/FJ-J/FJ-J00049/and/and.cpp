#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a[200010], ans = 0;
bool ok = true;

signed main(){
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if( ( a[i] & (a[i] + 1) ) != 0 )ok = false;
	}
	sort(a + 1, a + n + 1);
	if(ok == true){
		cout << a[n - m + 1] << "\n";
		return 0;
	}
	
	for(int i = 1; i + m - 1 <= n; i++){
		int now = a[i];
		for(int j = i + 1; j <= i + m - 1; j++)now &= a[j];
		ans = max(ans, now);
	}
	cout << ans << "\n";
	
	return 0;
}

/*

6 2
63 31 15 7 3 1

*/
