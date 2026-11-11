#include <bits/stdc++.h>
using namespace std ;
vector<int> e[5000005] ;
int n , a[2000005] , d , c , t , ans , sum , minn ;
void dfs(int s , int t1 , int step)
{
	if (s == t1){
		if (step < minn) {
			minn = step ;
			sum = 1 ;
			
		}
		else if (step == minn) sum++ ;
	}
	for (int i = 0 ;  i < e[s].size() ; i++){
		int v = e[s][i] ;
		if (v > t1) return ;
		//cout << s << " " << v << " " << sum << endl ;
		dfs(v , t1 , step + 1) ;
	}
	return ;
}
int main()
{
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	cin >> c >> t ; 
	while(t--){
		for (int i = 1 ; i <= n ; i++)
		{
			e[i].clear() ;
		}
		ans = 0 ;
		cin >> n >> d ;
		for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
		for (int i = 1 ; i <= n ; i++){
			for (int j = i + 1 ; j <= n ; j++){
				if (a[j] - a[i] <= d){
					e[i].push_back(j) ;
					//e[j].push_back(i) ;
				} 
			}
		}
		for (int i = 1 ; i <= n ; i++){
			for (int j = i + 1 ; j <= n ; j++){
				sum = 0 ;
				minn = 11451400 ;
				dfs(i , j , 0) ;
				if (sum == 2){
					//cout << i << " " << j << endl ;
					ans++ ;
				} 
				//cout << minn << " " ;
			}
		}
		cout << ans << endl ;
		//cout << endl ;
	} // 0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
	//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
	return 0 ;
}

