#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll nn = 2e5 + 10;
int a, b[nn], n, m, ant = 1;
int maxx;

int main(){
	freopen( "and.in", "r", stdin );
	freopen( "and.out", "w", stdout );
	cin >> n >> m;
	for( int i = 1; i <= n; i++ ){
		cin >> b[i];
	}
	if( m == 1 ){
		sort( b + 1, b + 1 + n );
		cout << b[n];
		return 0;
	}
	for( int i = 1; i <= n; i++ ){
		for( int j = i + 1; j <= n; j++ ){
			if( b[i] % 2 == b[j] % 2 ){	
				a = ( b[i] & b[j] );
				maxx = max( a, maxx );
			}
		}
	}
	cout << maxx << endl;
	return 0;
}
