#include <bits/stdc++.h>
using namespace std ;
int n , m ;
int a[500005] , len[500005] , t[500005] , num[55] , g[55] ;
bool b[250005][45] , h[250005][45] ; 
long long sum ;
bool cmp (int a , int b) {
	return a > b ;
}
int f (int x , int q) {
	int p = 1 ;
	while (x > 0) {
		b[q][p] = x & 1 ;
		if (b[p][q]) num[q]++ ;
		x >>= 1 ;
		p++ ;
	}
	return p - 1 ;
}
int f2 (int x) {
	for (int i = x ; i >= 1 ; i--) {
		if (num[i] >= m) {
//			cout << i << " " ;
			return i ;
		} 
	}
	return 0 ;
}
int f3 (int u , int y) {
	for (int i = 1 ; i <= y ; i++) {
		if (len[i] < u) {
			return i - 1 ;
		} 
	}
}
void f4 (int p , int q , int l) {
	for (int i = 1 ; i <= q ; i++) {
		h[l][i] = b[p][i] ;
		if (b[p][i]) num[i]++ ;
	}
}
void f5 (int l , int u) {
	for (int i = 1 ; i <= l ; i++) {
		for (int j = 1 ; j <= u ; j++) {
			b[i][j] = h[i][j] ;
			h[i][j] = 0 ;
		}
	}
}
void f6 (int x , int y) {
	int u = f2 (x) ;
//	cout << u << "%" ;
	if (u == 0) return ;
	sum += 1 << (u - 1) ;
//	cout << u - 1 << "$" ;
	int v = f3 (u , y) ;//前v个数中存在满足m个数&结果最大 
//	cout << v << "#" ;
	
	for (int i = 1 ; i <= 30 ; i++) {
		num[i] = 0 ;
	}
	int l = 1 ;
	for (int i = 1 ; i <= v ; i++) {
		if (b[i][u] == 1) {
			f4 (i , u , l) ;
			l++ ;
		}
	}
	l-- ;
	f5 (l , u) ;
	f6 (u - 1 , v) ;
//	for (int i = u - 1 ; i >= 1 ; i++) {
//		if (num[i] >= m) f6 (i , v) ;
//	}
}
int main () {
	freopen ("and.in" , "r" , stdin) ;
	freopen ("and.out" , "w" , stdout) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i] ;
	}
	sort (a + 1 , a + 1 + n , cmp) ;
	for (int i = 1 ; i <= n ; i++) {
		len[i] = f (a[i] , i) ;
//		if (len[i] != len[i - 1]) {
//			t[k] = i - 1 ;
//			k++ ;
//		}
	}
	f6 (30 , n) ;
	cout << sum ;
	return 0 ; 
}
