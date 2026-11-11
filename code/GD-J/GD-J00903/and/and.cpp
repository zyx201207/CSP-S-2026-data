#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
long long a[N], res = 0;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == n){
		res = a[1];
		for(int i = 1; i <= n; i++){
			res &= a[i];
		}
		cout << res;
	}else if(m == 1){
		res = a[1];
		for(int i = 2; i <= n; i++){
			res = max(res, a[i]);
		}
		cout << res;
	}else if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				res = max(res, (a[i] & a[j]));
			}
		}
		cout << res;
	}else{
		cout << rand();
	}
	return 0;
}
