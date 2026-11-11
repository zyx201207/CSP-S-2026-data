#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 2 * 1e5 + 5;
int a[MAXN];
int n , m;
int ans = -1;
void dfs(int t , int sum , int now){
	if(now == m){
		ans = max(ans , sum); return;
	}
	for(int i = t + 1 ; i <= n ; i++){
		dfs(i , sum & a[i] , now + 1);
	}
	return;
}
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n - m ; i++){
		dfs(i , a[i] , 1);
	}
	cout << ans;
	return 0;
}
