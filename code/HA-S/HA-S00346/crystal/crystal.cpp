#include<bits/stdc++.h>
using namespace std;
int n, m, a[500001], l, r;

bool pd(int a, int b){
	return a < b;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m >> l;
	for (int i = 1; i <= n - 1; i++){
		cin >> r;
		a[i] = r - l;
		l = r;
	}
	for (int i = n - 1; i >= 1; i--){
		for (int j = 1; j <= n - i; j++){
			int cnt = 0;
			for (int k = j; k <= j + i - 1; k++) cnt += a[k] * (k - j + 1);
			if (cnt <= m){
				cout << i + 1;
				return 0;
			}
		}
	}
	
	return 0;
}
