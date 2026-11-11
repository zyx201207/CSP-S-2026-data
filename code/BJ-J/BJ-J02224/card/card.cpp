#include<bits/stdc++.h>
using namespace std;

const int nn = 5e5, mm = 3e5;
int a[nn], b[mm], n, m;
int c[mm]; 

int main(){
	freopen( "card.in", "r", stdin );
	freopen( "card.out", "w", stdout );
	cin >> n >> m;
	for( int i = 1; i <= n; i++ ){
		cin >> a[i];
	}
	for( int i = 1; i <= n; i++ ){
		for( int j = 0; j <= m; j++ ){
			b[j] = 0;
		}
		for( int j = i; j <= n; j++ ){
			b[a[j]]++;
			if( b[a[j]] > 1 ){
				for( int k = j; k >= 1; k-- ){
					if( a[k] == a[j] && k != j ){
						break;
					}
					b[a[k]]--;
				}
			}
		}
		for( int j = 1; j <= m; j++ ){
			if( b[j] > 0 ){
				c[j]++;
			}
		}
	}
	for( int i = 1; i <= m; i++ ){
		cout << c[i] << " ";
	}
	return 0;
}

