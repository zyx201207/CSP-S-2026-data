#include<bits/stdc++.h>
using namespace std ;
vector<unsigned long long> p[35] ;
const int N = 2e6 + 5 ;
unsigned long long b[N] ;
int main(){
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
//	cout << "1<< 30="<< (1ull << 30 )<< " ";
	int n , m;
	cin >> n >> m;
	for(int i = 0 ; i <= 303 ; i++){
		p[i].clear() ;
	}
	for(int i = 1 ; i <= n ; i ++){
		cin >> b[i] ;
		for(int j = 30 ; j >= 1 ; j --){
			if((1ull << j) <= b[i]){
//				cout << "j="<< j << " " ;
//				cout << "b[i]="<< b[i]<< " " ;
				p[j].push_back(b[i]) ;
				break ;
			}
		}
	}
//	for(int i = 0 ; i < p[18].size() ; i ++){
//		cout << p[18][i]<< " " ;
//	}
//	cout << "\n" ;
//	cout << "m="<< m << " " ;
	for(int i = 30 ; i >= 2 ; i --){
//		cout << "i="<< i << " " ;
		sort(p[i].begin() , p[i].end() , greater<int>()) ;
		int q = p[i].size() ;
		for(int j = 0 ; j < p[i].size() ; j ++){
			if(p[i][j] == 0){
				q = j ;
			}
		}
		if(p[i].empty()){
			continue ;
		}
		if(q >= m){
//			cout << "i="<< i <<" " ;
//			for(int j = 0 ; j < p[i].size() ; j ++){
//				cout << p[i][j] << " " ;
//			}
//			cout << "in " ;
			unsigned long long d = p[i][0] ;
//			cout << "d="<< d << " " ;
//			cout << "d="<< d << " " ;
			for(int j = 1 ; j < m ; j ++){
//				cout << "in " ;
//				cout << "p[i][j]="<< p[i][j] << " " ;
				d &= p[i][j] ;
//				cout << "d="<< d << " " ;
			}
			cout << d ;
			return 0 ;
		}
		else{
			for(int j = 0 ; j  < p[i].size() ; j ++){
				p[i][j] -= (1ull << i) ;
				p[i - 1].push_back(p[i][j]) ;
			}
		}
	}
	return 0 ;
}
