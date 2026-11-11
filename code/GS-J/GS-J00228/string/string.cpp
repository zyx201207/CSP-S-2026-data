#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, ans;
long long a[N];
char b[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n ;i++){
		cin >> a[i] >> b[i];
	}
	int l = 1, r = n;
	for(int i = 1; ; i ++){
		if(a[l] == 0){
			l ++;
		}
		if(a[r] == 0){
			r--;
		}
		if(l == r){
			cout << ans;
			return 0;
		}else if(a[l] == 0 && a[r] == 0 && l+1 == r){
			cout << ans;
			return 0;
		}
		if(b[l] != b[r]){
			if(a[l] >= a[r]){
				ans += a[r];
				a[l] -= a[r];
				a[r] = 0;
			}else{
				ans += a[l];
				a[r] -= a[l];
				a[l] = 0;
			}
		}else{
			if(a[l] >= a[r]){
				
				a[l] -= a[r];
				a[r] = 0;
			}else{
				
				a[r] -= a[l];
				a[l] = 0;
			}
		}
		
		 
	}
	return 0;
}

