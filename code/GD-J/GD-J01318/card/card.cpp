#include<bits/stdc++.h>
using namespace std ; 
const int KN = 5e5 + 10 , KM = 3e5 + 10 ;
int a[KN] ;  
int start[KM] ;
int ended[KM] ; 
int f[KM] ; 
int n , m ; 
struct node {
	int st , ed ; 
};
bool operator< (node a , node b) {
	return a.st < b.st ; 
}
node q[KM] ; 
map <int , int> mp ; 
bool vis[KN] ; 
int main () {
	freopen ("card.in" , "r" , stdin ) ; 
	freopen ("card.out" , "w" , stdout ) ; 
	memset (a , 0 , sizeof (a) ) ;
	scanf ("%d%d" , &n , &m ) ;
	for (int i = 1 ; i <= n ; i ++ ) {
		scanf ("%d" , &a[i] ) ; 
		if (! mp[a[i]] ) {
			start[a[i]] = i ; 
		}
		ended[a[i]] = i ; 
		mp[a[i]] ++ ; 
	}
	memset (f , 1 , sizeof (f) ) ; 
	f[a[n]] = n ; 
	for (int i = 1 ; i <= m ; i ++ ) {
		q[i] = {start[i] , ended[i] } ; 
	}
	sort (q + 1 , q + m + 1 ) ; 
	sort(a + 1 , a + n + 1 ) ; 
	for (int i = n - 1 ; i > 0 ; i -- ) {
		if (f[i] ) continue ; 
		for (int j = 1 ; j <= m ; j ++ ) {
			if (mp[a[i + 1]] > 1 ) {
				if (i <= q[j].st || i >= q[j].ed ) f[a[i]] += q[j].st ; 
			}else {
				f[a[i]] += f[a[i + 1]] ; 
			}
		}
		
	}
	for (int i = 1 ; i <= m ; i ++ ) printf ("%d " , f[i] ) ;  
	return 0 ; 
} 
