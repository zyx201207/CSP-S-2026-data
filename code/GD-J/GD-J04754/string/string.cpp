#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n,ans = 0;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	bool f = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		if(a[i] != a[i - 1]){
			f = 0;
		}
	}
	if(f == 1){
		cout << "0";
		return 0;
	}
	int r = n;
	for(int l = 1; l <= r;){
		if(a[l] == a[r]){
			if(c[l] != c[r]){
				ans += a[l]; 
			}
			r--;
			l++;
		}else{
			if(a[l] > a[r]){
				if(c[l] != c[r]){
					ans += a[r];
				}
				a[l] -= a[r];
				r--;
			}else{
				if(c[l] != c[r]){
					ans += a[l];
				}
				a[r] -= a[l];
				l++;
			}
		}
	}
	cout << ans;
	return 0;
} 	
