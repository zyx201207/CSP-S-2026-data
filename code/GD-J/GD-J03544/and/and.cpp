#include<bits/stdc++.h>
using namespace std;

int n;
int a[200010];
int s;

bool cmp( int a, int b ){
	return a > b;
}

int main(){
	
	freopen( "and.in", "r", stdin );
	freopen( "and.out", "w", stdout );
	
	int m;
	cin >> n >> m;
	for( int i = 1; i <= n; i++ ){
		cin >> a[i];
	}
	
	sort( a + 1, a + 1 + n, cmp );
	s = a[1];
	for( int i = 1; i <= m; i++ ){
		s &= a[i];
	}
	
	cout << s;
	
	
	
	
	return 0;
} 
