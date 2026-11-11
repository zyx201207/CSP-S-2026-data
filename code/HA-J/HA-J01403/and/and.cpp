#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200005], ans = 0;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);	
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 0; i < n; ++i){
			ans = max(ans,a[i]);
		}
		cout << ans ;
		return 0;
	}
	if(m == 2){
		for(int i = 0; i < n-1; ++i){
			for(int j = i+1; j < n; ++j){
				ans = max(ans,(a[i]&a[j]));
			}
		}
		cout << ans;
		return 0;
	}
	if(m == n){
		ans = a[0];
		for(int i = 1; i < n; ++i){
			ans = (ans&a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m == n-1){
		for(int i = 0; i < n; ++i){
			long long t = 0;
			for(int j = 0; j<n; ++j){
				if(j != i){
					t = (t&a[j]);
				}
			}
			ans = max(ans,t);
		}
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
