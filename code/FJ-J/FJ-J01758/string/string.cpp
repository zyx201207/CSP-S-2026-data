#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans = 0;
long long a[200005];
char c[200005];
string s;

int main (){
	freopen( "string.in", "r", stdin );
	freopen( "string.out", "w", stdout );
	scanf( "%d", &n );
	for ( int i=1; i<=n; i++ ){
		scanf( "%lld", &a[i] );
		cin >> c[i];
	}
	int l=1, r=n;
	while ( l < r ){
		if ( c[l] == c[r] ){
			l++;
			r--;
		}
		else{
			if ( a[l] < a[r] ){
				a[r] -= a[l];
				ans += a[l];
				l++;
			}
			else if ( a[l] > a[r] ){
				a[l] -= a[r];
				ans += a[r];
				r--;
			}
			else{
				ans += a[l];
				l++;
				r--;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

