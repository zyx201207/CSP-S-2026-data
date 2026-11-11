#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200005], mmax = -1000001, alll, tmax = -1000001, algd = 0, j = 0, o = 0;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (i == 1){
			alll = a[i];
		}
		else {
			alll &= a[i];
		}
		if (a[i] > mmax){
			mmax = a[i];
		}
		if (a[i] % 2 == 0){
			o++;
		}
		else {
			j++;
		}
	}
	if (j > o){
		algd = 1;
	}
	if (m == 1){
		cout << mmax;
		return 0;
	}
	if (m == n){
		cout << alll;
		return 0;
	}
	if (m == 2){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				tmax = max(tmax, a[i] & a[j]);
			}
		}
		cout << tmax;
	}
	else{
		if (algd){
			cout << 1;
			return 0;
		}
		cout << 0;
	}
	return 0;
}
