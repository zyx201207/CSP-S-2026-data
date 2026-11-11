#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	bool flagB = false;
	bool flagA = true;
	int B = 0;
	for(int i = 0; i <= 31; i++){
		if(n == pow(2, i)){
			flagB = true;
			B = i;
		}
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		bool ff = false;
		for(int j = 1; j <= 31; j++){
			if(a[i] == pow(2, j)-1){
				ff = true;
			}
		}
		if(ff == true && flagA == true){
			flagA = true;
		}else{
			flagA = false;
		}
		if(a[i] != i-1){
			flagB = false;
		}
	}
//	cout << flagB << ' ' <<  flagA; 
	long long ans = -999;
	if(m == 1){
		for(int i = 1; i <= n; i++){
			ans = max(ans, a[i]);
		}
	}else if(m == n){
		ans = a[1];
		for(int i = 2; i <= n; i++){
			ans &= a[i];
		}
	}else if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				ans = max(ans, a[i]&a[j]);
			}
		}
	}else if(m == n-1){
		long long sum = pow(2, 31)-1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(j == i){
					continue;
				}else{
//					cout << sum << '&' << a[j] << ' ';
					sum &= a[j];
				}
			}
//			cout << '=' << sum;
			ans = max(ans, sum);
			sum = pow(2, 31)-1;
		}
	}else if(flagA){
		sort(a+1, a+n+1);
		ans = a[m];
	}else if(flagB){
		ans = a[n];
		for(int i = n-1; i >= n-m+1; i--){
			ans &= a[i];
		}
	}
	cout << ans;
	return 0;
}
