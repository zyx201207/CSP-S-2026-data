#include <bits/stdc++.h>
using namespace std ;

int main() {
	
	freopen ("card.in","r",stdin) ;
	freopen ("card.out","w",stdout) ;
	
	long long n , m ;
	cin >> n >> m ;
	
	vector <long long> numS (n) ;
	
	for (long long i = 0 ; i < n ; i++){
		cin >> numS[i] ;
	}
	vector <long long> ans (m,0) ;
//	for (long long x = 0 ; x < n ; x ++){
//		vector <long long> num_berS ;
//		vector <long long> num_pos (m,0) ;
//		for (long long i = x , temp = 0 ; i < n ; i++) {
//			if (num_pos[numS[i]]){
//				for (long long i = temp ; i >= numS[i] ; i++){
//					num_pos[i] = 0 ;
//					num_berS.pop_back() ;
//				}
//				temp++;
//				num_berS.push_back(numS[i]) ;
//			}else{
//				num_pos[numS[i]] = temp ;
//				temp++;
//				num_berS.push_back(numS[i]) ;
//			}
//		}
//		for (long long i : num_berS){
//			ans[i]++;
//		}
//	}
	for (long long i : numS){
		ans[i]++;
	}	
	for (long long i:ans) {
		cout << i << " " ;
	}
	
	return 0 ;
}
