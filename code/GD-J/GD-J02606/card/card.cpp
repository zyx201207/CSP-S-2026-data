#include <bits/stdc++.h> 
using namespace std ;
int a[500005] , n , m , b[500005] , ans[300005] , pos[300005] ;
void play(int now)
{
	memset(b , 0 , sizeof(b)) ;
	memset(pos , 0 , sizeof(pos)) ;
	int tail = 0 ;
	for(int i = now ; i <= n ; i++){
		if (!pos[a[i]] || pos[a[i]] > tail) {
			b[++tail] = a[i] ;
			pos[a[i]] = tail ;
		}
		else {
			if (pos[i] <= tail)
				tail = pos[a[i]] ;
		}
//		if (now == 6){
//			for (int i = 1 ; i <= tail ; i++) cout << b[i] << " " ;
//			cout << endl ;
//		}
	}
	for (int i = 1 ; i <= m ; i++){
		if (pos[i] <= tail && pos[i] != 0 && b[pos[i]] == i) ans[i]++ ;
	}
		
//	for (int i = 1 ; i <= m ; i++){
//		cout << ans[i] << " " ;
//	}
//	cout << endl ;
	
}
int main()
{
	freopen("card1.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
	for (int i = 1 ; i <= n ; i++){
		play(i) ;
	}
	for (int i = 1 ; i <= m ; i++){
		cout << ans[i] << " " ;
	}
	//10 3 3 1 2 1 3 2 3 1 2 1
}
