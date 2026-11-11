#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 5 ;
int a[N] ;
bool b[N] ;
int d[N] ;
stack<int> s ;
int main(){
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	int n , m ;
	cin >> n >> m;
//	cout << "in " ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] ;
	}
//	cout << "in " ;
	for(int i = 1 ; i <= n ; i ++){
//		cout << "in " ;
		while(!s.empty()){
			s.pop() ;
		}
//		cout << "in " ;
		for(int j = 1 ; j <= n ; j ++){
			b[j] = 0 ;
		}
//		cout << "in " ;
		for(int j = i ; j <= n ; j ++){
//			cout << "in " ;
			if(!b[a[j]]){
				s.push(a[j]) ;
				b[a[j]] = 1 ;
			}
			else{
//				cout << "s.size="<< s.size() << " " ;
				while(s.top() != a[j]){
					b[s.top()] = 0 ;
					s.pop() ;
				}
			}
		}
//		cout << "in " ;
		while (!s.empty()){
			d[s.top()] ++ ;
			s.pop() ;
		}
	}
//	cout << "in " ;
	for(int i = 1 ; i <= m ; i ++){
		cout << d[i]<< " " ;
	}	
	return 0 ;
}
