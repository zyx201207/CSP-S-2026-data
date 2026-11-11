#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[35];
int jm[200005] = {};
int c[35] = {};
int n,m;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int N = 1;
	for (int i = 30; i >= 1; i--){
		b[i] = N;
		N *= 2;
	}
	bool f = 1;
	for (int i = 1; i <= 30; i++){
		int g = 0;
		for (int j = 1; j <= n; j++){
			if (a[j] >= b[i] && jm[j] == 0){
				g++;
			}
			else{
				jm[j] = 1;
			}
		}
		if (g >= m){
			c[i] = 1;
			f = 0;
			for (int j = 1; j <= n; j++){
				if (a[j] >= b[i]){
					a[j] -= b[i];
				}
			}
		}
		else if (f){
			for (int j = 1; j <= n; j++){
				if (a[j] >= b[i]){
					a[j] -= b[i];
				}
				jm[j] = 0;
			}
		}
		else{
			for (int j = 1; j <= n; j++){
				if (a[j] >= b[i]){
					a[j] -= b[i];
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 30; i++){
		if (c[i] == 1){
			ans += b[i];
		}
	}
	cout << ans;
	return 0;
}
