#include<bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int t[100010];
stack <int> s;

int main(){
	
	freopen( "card.in", "r", stdin );
	freopen( "card.out", "w", stdout );
	
	cin >> n;
	for( int i = 1; i <= n; i++ ){
		cin >> a[i];
	}
	
	for( int i = 1; i <= n; i++ ){
		for( int j = i; j <= n; j++ ){
			if( t[a[i]] ){
				
			}
			t[a[i]] = 1;
			s.push( a[i] );
		}
	}
	
	
	
	
	
	
	
	return 0;
} 
