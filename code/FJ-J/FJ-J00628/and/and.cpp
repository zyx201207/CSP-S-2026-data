#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;



long long a[200005], n;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	long long m;
	cin >> n >> m;
	
	for(long long i = 0; i < n; i ++ ) cin >> a[i];
	
	if(m == 1){
		long long ans = 0;
		for(long long i = 0; i < n; i ++ ) ans = max(ans, a[i]);
		cout << ans;
		
		return 0;
	}else if(m == 2){
		long long ans = 0;
		for(long long i = 0; i < n; i ++ ){
			for(long long j = 0; j < n; j ++ ){
				if(i != j){
					ans = max(ans, a[i] & a[j]);
				}
			}
		}
		cout << ans;
		
		return 0;
	}else if(n == m){
		long long ans = a[0];
		for(long long i = 1; i < n; i ++ ){
			ans = ans & a[i];
		}
		cout << ans;
		
		return 0;
	}
}
