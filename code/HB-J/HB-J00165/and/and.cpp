# include <bits/stdc++.h>
using namespace std;

const int H = 200001;
int s[H][32] , t1[32] , s1[H] , l[32] , n , m;

int main ( ) {
	freopen ( "and.in" , "r" , stdin );
	freopen ( "and.out" , "w" , stdout );
	long long u = 1;
	for ( int i = 1 ; i <= 30 ; i++ , u *= 2 )
		l[i] = u;
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ ) {
		int a1;
		s1[i] = 31;
		cin >> a1;
		for ( int j = 30 ; 1 <= j ; j-- )
			if ( a1 >= l[j] )
				s[++t1[j]][j] = i , a1 -= l[j];
	}
	int sum = 0 , b = 32;
	for ( int j = 30 ; 1 <= j ; j-- ){
		int ans = 0;
		if ( t1[j] >= m ){
			for ( int i = 1 ; i <= t1[j] ; i++ ){
				if ( b + 1 >= s1[s[i][j]] )
					ans++ , s1[s[i][j]] = j;
			}
			if ( ans >= m ) 
				b = j , sum += l[j];
		}
	}
	cout << sum;
}
