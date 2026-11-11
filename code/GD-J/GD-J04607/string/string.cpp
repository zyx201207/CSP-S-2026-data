#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
bool _;
int a[N];
char c[N];
bool __;
signed main() {
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	//cout << (&_ - &__) * 1.0 / 1024.0 / 1024.0 << " ";
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	long long sum = 0;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int ans = 0;
	int l = 1 , r = n;
	for ( ; l < r ;) {
		int t = min(a[l] , a[r]);
		a[l] -= t;
		a[r] -= t;
		if (c[l] != c[r]) ans += t;
		if (a[l] == 0) l ++;
		if (a[r] == 0) r --;
		
	}
	cout << ans;
	return 0;
} 
/*
6
100000000 a
100000000 a
100000000 a
100000000 b
100000000 b
100000000 b

100pts?
*/
