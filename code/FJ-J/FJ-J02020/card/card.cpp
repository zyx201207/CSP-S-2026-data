#include<bits/stdc++.h>
using namespace std ;
long long c[500005] ;
long long sum[300005] ;
long long w[300005] ;
int main() {
	freopen("card.in" ,"r" ,stdin ) ;
	freopen("card.out" ,"w" ,stdout ) ;
	int n ,m ;
	cin >> n >> m ;
	for(int i = 1 ;i <= n ;i++ ) {
		cin >> c[i] ;
	}
	for(int i = n ;i >= 1 ;i-- ) {
		memset(w ,0 ,sizeof w ) ;
		stack<int> s ;
		for(int j = n - i + 1 ;j <= n ;j++ ) {
			if(w[c[j]] == 0 ) {
				w[c[j]] = j ;
				s.push(c[j]) ;
			}
			else {
				int uu = w[c[j]] ;
				for(int l = 1 ;l <= j - uu ;l++ ) {
					w[s.top()] = 0 ;
					s.pop() ;
				}
				s.push(c[j]) ;
			}
		}
		while(!s.empty()) {
			sum[s.top()]++ ;
			s.pop() ;
		}
	}
	for(int i = 1 ;i <= m ;i++ ) cout << sum[i] << " " ;




	return 0 ;
}

