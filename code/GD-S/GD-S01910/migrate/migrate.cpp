#include <bits/stdc++.h>
#define int long long
using namespace std;
int c , t , d , n;
const int maxn = 3e6 + 10;
int a[maxn] , cnt , ds[maxn] , res[maxn];
//bool check(){ 
//	for(int i = 3 ; i <= n ; i++){
//		if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]) return false;
//	}
//	return true;
//}
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i];
		}
		int ans = 0;
		for(int u = 1 ; u <= n ; u++){
			memset(res , 0 , sizeof(res));
			for(int i = 1 ; i <= n ; i++){
				ds[i] = 1e18;
			}
			ds[u] = 1;
			res[u] = 1;
			for(int k = u + 1 ; k <= n ; k++){
				cnt = 0;
				for(int g = k - 1 ; g >= 1  ; g--){
					if(a[k] - a[g] > d) break;
					else{
						ds[k] = min(ds[k] , ds[g] + 1);
					}
				}
//				cout << k << ' ' << ds[k] << '\n';
				for(int g = k - 1 ; g >= 1  ; g--){
					if(a[k] - a[g] > d) break;
					if(ds[k] - ds[g] == 1){
						cnt += res[g];
						res[k] = cnt;
					}
				}
				if(cnt == 2) ++ans;
			}
			
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
 

*/
