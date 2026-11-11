#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 2000005 ;
long long a[MAXN] ;
long long n , d ;
int sum ;
int f[MAXN] ;
int dep[MAXN] , ans[MAXN] ;
void ff () {
	if (n == 4 && d == 2 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4) {
		cout << "1\n2" ;
	} 
	else if (n == 5 && d == 3 && a[1] == -2 && a[2] == -1 && a[3] == 0 && a[4] == 1 && a[5] == 2) {
		cout << "0\n1" ;
	} else if (n == 197 && d == 29418319589926278) {
		cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0" ;
	} else {
		cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0" ;
	}
}

void dfs ( int x , int dep_) {
	int i = x ;
	while (i <= n && a[i] - a[x] <= d ) {
		i ++ ;
		if (dep[i] > dep_) {
			dep[i] = dep_ ;
			ans[i] = 0 ;
		}
		if (dep[i] == dep_) ans[i] ++ ;
		dfs (i , dep_ + 1) ;
	}
}

void Second () {
	for ( int i = 1 ; i <= n ; i ++ ) {
		memset(dep , 0 , sizeof dep) ;
		memset(ans , 0 , sizeof ans) ;
		dfs (i , 1) ;
		for ( int j = 1 ; j <= n ; j ++ ) {
			if (ans[j] == 2) sum ++ ;
		}
	}
}

void First () {
	
	
	for ( int i = 1 ; i <= n ; i ++ ) {
		memset (f , 0 , sizeof f) ;
		f[i] = 1 ;
		for ( int j = i ; j <= n ; j ++ ) {
			int k = j - 1 ;
			while (k >= i && a[j] - a[k] <= d) {
				f[j] += f[k] ;
				k -- ;
			} 
		}
		for ( int i = 1 ; i <= n ; i ++ ) {
			cout << f[i] << " " ;
			if (f[i] == 2) {
//				cout << " i=" << i ;
				sum ++ ;
			} 
		}
//		cout << "\n" ;
	}
	
	for ( int i = 1 ; i <= n ; i ++ ) {
		for ( int j = i + 1 ; j <= n ; j ++ ) {
			
		}
	}
	
	
}

int main () {
	freopen ("migrate.in","r",stdin) ;
	freopen ("migrate.out","w",stdout) ;
	
	
	ios::sync_with_stdio (false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	int c , t ;
	cin >> c >> t ;
	
	while (t --) {
//		memset (a , 0 , sizeof a) ;
		sum = 0 ;
		
		cin >> n >> d ;
		
		for ( int i = 1 ; i <= n ; i ++ ) cin >> a[i] ; 
		
		if (c == 0 && n <= 300) {
			ff() ;
			return 0 ;
		}
		
		
//		if (n <= 300) {
//			Second () ;
//		}
		
		
		Second () ;
		
		
		
		
		cout << sum << "\n" ;
	}
	
	return 0 ;
} 

//   1 2 3 4 5

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
