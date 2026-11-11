#include<bits/stdc++.h>
using namespace std;
int arr[200005],n,m;
int arrid[35][200005];
int arrpos[35],arrvis[200005];
int arridvis[200005];
int ans = 0;
int poww( int a , int b ){
	int sum = 1;
	for ( int i = 1 ; i <= b ; i++ ){
		sum *= a;
	}
	return sum;
}
int main(){
	freopen ( "and.in" , "r" , stdin );
	freopen ( "and.out" , "w" , stdout );
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> arr[i];
		int sss = arr[i],Pos = 0;
		while ( sss ){
			arrid[Pos][i] = ( sss % 2 );
			sss /= 2;
			arrvis[i] = Pos;
			Pos++;
		}
	}
	for ( int i = 0 ; i <= 30 ; i++ ){
		for ( int j = 1 ; j <= n ; j++ ){
			arrpos[i] += arrid[i][j];
		}
	}
	for ( int i = 30 ; i >= 0 ; i-- ){
		if ( arrpos[i] >= m ){
			ans += poww ( 2 , i );
			for ( int j = 1 ; j <= n ; j++ ){
				if ( arrid[i][j] == 0 && arridvis[j] == 0 ){
					arridvis[j] = 1;
					for ( int k = 0 ; k <= arrvis[j] ; k++ ){
						arrpos[k] -= arrid[k][j];
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
