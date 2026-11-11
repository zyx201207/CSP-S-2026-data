#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n,m;
long long a[N];
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;  
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n == m){
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			long long k = a[i] & ans;
			ans = k;
		}
		cout << ans << endl;
		return 0;
	}else if(m == n - 1){
		long long tmax = 0;
		for(int i = 1; i <= n; i++){
			long long ans = 0;
			for(int j = 1; j <= n; j++){
				if(j != i){
					ans = ans & a[j];
				}
			}
			tmax = max(tmax , ans);
		}
		cout << tmax << endl;
	}else if(m == 1){
		long long tmax = 0;
		for(int i = 1; i <= n; i++){
			tmax = max(a[i] , tmax);
		}
		cout << tmax << endl;
	}
	long long tmax = 0; 
	int c,d;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			long long k = a[i] & a[j];
			if(k > tmax){
				tmax = k;    
			}
		}
	} 
	cout << tmax << endl;
	return 0;
} 
