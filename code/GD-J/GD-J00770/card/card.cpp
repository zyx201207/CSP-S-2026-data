#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 2e5 + 5 ;
const int MAXM = 1e5 + 5 ;
const int INF = 1e9 + 7 ;

int n, m ;
int a[MAXN], ans[MAXN], tmp[MAXN], last[MAXN] ;

inline void A() {
	for(int i = 1; i <= n; i++) ans[a[i]] = i ;
	for(int i = 1; i <= m; i++) printf("%d ", ans[i]) ;
	printf("\n") ;
	exit(0) ;
}

int main() {
	freopen("card.in", "r", stdin) ;
	freopen("card.out", "w", stdout) ; 
	
	scanf("%d %d", &n, &m) ;
	bool flagA = true ;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]) ;
		if(a[i] < a[i - 1]) flagA = false ;
		last[i] = INF ;
	}
	
	if(flagA) A() ;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) last[j] = INF ;
		
		int it = 1 ;
		for(int j = i; j <= n; j++) {
			if(last[a[j]] < it) it = last[a[j]] + 1 ;
			else last[a[j]] = it, tmp[it++] = a[j] ;
			
		}
		
		for(int j = 1; j < it; j++) ans[tmp[j]]++ ;
	}
	
	for(int i = 1; i <= m; i++) printf("%d ", ans[i]) ;
	printf("\n") ;
	
	return 0 ;
}

// 下次我会努力的！ 

