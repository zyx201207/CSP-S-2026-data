#include <bits/stdc++.h>
using namespace std ;

long long n , m ;
vector <long long> numS ;

int main() {
	
	freopen ("and.in","r",stdin) ;
	freopen ("and.out","w",stdout) ;
	
	cin >> n >> m ;
	
	for (long long i = 0 , temp ; i < n ; i++){
		cin >> temp ;
		numS.push_back(temp) ;
	}
	
	sort (numS.begin(),numS.end()) ;
	
	long long ans = numS[n-1] ;
	for (long long i = n-2 ; i >= n-m ; i--){
		ans &= numS[i] ;
	}
	
	cout << ans ;
	
	return 0 ;
}
