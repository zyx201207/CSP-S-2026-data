
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long n, m;
	cin >> n >> m;
	long a[n+1] = {};
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long b = a[2] - a[1];
	long c = m, d = 0;
	for (int i = 0; i <= m; i++){
		if (c >= b){
			c -= b;
			d++;
		}
	}
	long f = 0;
	for (int i = 1; i <= m; i++){
		if (d > f){
			f += i;
		}
		else{
			cout << i;
			break;
		}
	} 
}
