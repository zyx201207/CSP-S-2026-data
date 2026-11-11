#include<bits/stdc++.h>
using namespace std ;
int c , m , n ,d , p ;
int a[100010] , w[1010][1000] , o[100010] ;
int ans(int x , int y){
	int ans1 ;
	ans1+=a[x] ;
//	if(x == y) return ans1 ;
	for (int i = 1 ; i <= n ;i++ ){
		if(w[i][x] != 0){
		   ans1+=w[i][x];
		   if(x == y) return ans1 ;
		   ans1 += ans(x+1 ,y) ;
		}
	}
	return ans1 ;
}
int main(){
//	freopen("crystal.in","r",stdin) ;
//	freopen("crystal.out","w",stdout) ;
	cin >> c >> n >> m >> d >> p ;
	for (int i = 1 ; i <= m ; i++){
		cin >> a[i] ;
	}
	for (int i = 1 ; i <= n ; i++){
		int p ;
		cin >> p ;
		for (int j = 1 ; j <= p ;j++){
			int a1 , a2 ;
			cin >> a1 >> a2 ;
			w[i][a1] = a2 ;
		}
	}
	for (int i = 1 ; i <= p ; i++){
		int x , y ;
		cin >> x >> y ;
		cout << ans(x,y) << endl ;
	}
	return 0 ;
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6
3 2 3 3 4 5 7 
1 3 
1 2 
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
