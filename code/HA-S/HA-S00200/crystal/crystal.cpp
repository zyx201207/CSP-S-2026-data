#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], c[500005];
int sum;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n - 1; i++){
		for (int j = i + 1; j <= n; j++){
			c[i] = min(a[i], a[j]);
		}
	}
	for (int i = 1; i <= n; i++){
		a[i] = c[i];
	}
	for (int i = 2; i <= n; i++){
		for (int j = i - 1; j >= 1; j--){
			sum += a[i] - a[j];
			if(sum == m){
				cout << i;
				break;
			} 
			if(sum > m){
				cout << i - 1;
				break;
			}
		}
		if(sum == m) break;
		else if(sum > m) break;
		else sum = 0;
	}
	return 0;
}
