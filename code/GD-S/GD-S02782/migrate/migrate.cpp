#include<bits/stdc++.h>
using namespace std ;
const int N=2e6+10 ;
int x[N] ; 
int main(){
	freopen("migrate.in","r",stdin) ;
	freopen("migrate.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	int c,t ;
	cin >> c >> t ;
	while(t--){
		int n,d ;
		cin >> n >> d ;
		for(int i=1;i<=n;i++){
			cin >> x[i] ;
		}
		if(n==1||n==2){
			cout << 0 ;
		}
		else{
			cout << n-1 ;
		}
	}
	return 0 ;
}
