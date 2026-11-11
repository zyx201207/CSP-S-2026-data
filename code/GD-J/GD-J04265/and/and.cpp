#include <bits/stdc++.h>
using namespace std;
int n, m;
int mx = 0;
int a[2010];
int mxval = 0;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	for(int i = 1; i <= 20; ++i){
		a[i] = 4194303;
	}
	cin >> n >> m;
	cin >> a[1];
	int ans = a[1];
	mx = a[1];
	for(int i = 2; i <= n; ++i){
		cin >> a[i];
		ans &= a[i];
		if(a[i] > mx){
			mx = a[i];
		}
	}
	if(m == n){
		cout << ans;
		return 0;
	}
	if(m == 1){
		cout << mx;
		return 0;
	}
	if(m == 2){
		int mx = 0;
		for(int i = 1; i < n; ++i){
			for(int j = i + 1; j <= n; ++j){
				int add = a[i] & a[j];
				if(add > mx){
					mx = add;
				}
			}
		}
		cout << mx;
		return 0;
	}
	if(m == n - 1 && n > 20){
		int mx = 0;
		for(int i = 1; i <= n; ++i){
			int add = 4194303;
			for(int j = 1; j <= n; ++j){
				if(j != i){
					add &= a[j];
				}
			}
			if(add > mx){
				mx = add;
			}
		}
		cout << mx;
		return 0;
	}
	if(n <= 20){
		int mxk = 0;
		for(int k = 0; k <= (1 << n); ++k){
			int cnt = 0;
			for(int i = 0; i <= 20; ++i){
				if((k >> i) & 1){
					cnt ++;
				}
			}
			if(cnt != m){
				continue;
			}
			int sum = 4194303;
			for(int i = 0; i < 20; ++i){
				if((k >> i) & 1){
					sum &= a[i + 1];
				}
			}
			if(sum > mxk){
				mxk = sum; 
			}
		}	
		cout << mxk;
		return 0;
	}
	return 0;
} 
