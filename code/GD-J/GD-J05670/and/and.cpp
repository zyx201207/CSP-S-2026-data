#include<bits/stdc++.h>
using namespace std;
const int A = 2e5 + 10;
int n, m, ans;
int a[A];
int main(){
	freopen("and.in", "w", stdin);
	freopen("and.out", "r", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 1; i <= n; i++){
			ans = max(ans, a[i]);
		}
		cout << ans;
		return 0;
	}
	else if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
//	else{
//		while(m--){
//			for(int i = 1; i <= n; i++){
//				
//			}
//		}
//	}
	
	
	return 0;
} 
