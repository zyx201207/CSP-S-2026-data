#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, m, cnt, a[N]; char c[N];
int main () {
	freopen ( "string.in", "r", stdin );
	freopen ( "string.out", "w", stdout );
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for ( int i = 1; i <= n; i ++ ) {
		cin >> a[i] >> c[i];
		m += a[i]; 
	}
	long long x = 1, y = n, now = 1;
	while ( now <= m + 1 - now ) {
		int t = min ( a[x], a[y] );
		if ( a[x] == a[y] ) {
			now += a[x];
			a[x] = a[y] = 0;
			if ( c[x] != c[y] ) 
				cnt += t;
			x ++;
			y --;
		}
		else if ( t == a[x] ) {
			now += a[x];
			a[x] = 0;
			if ( c[x] != c[y] ) 
				cnt += t;
			x ++;
			a[y] -= t;
		}
		else {
			now += a[y];
			a[y] = 0;
			if ( c[x] != c[y] )
				cnt += t;
			y --;
			a[x] -= t;
		}
	}
	cout << cnt << '\n';
	return 0;
}
