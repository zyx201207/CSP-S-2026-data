#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll n , a[N];
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];

	int l = 1,r = n;
	ll ans = 0;
	while( l < r ) {
		ll pp = min( a[l] , a[r] );
		if( c[l] != c[r] ) ans += pp;
		a[l] -= pp , a[r] -= pp;
		if( !a[l] ) ++l;
		if( !a[r] ) --r;
	}
	cout << ans;
	return 0;
}
/*
6
5 a
2 z
1 a
3 b
2 c
3 a
ans : 5
*/
