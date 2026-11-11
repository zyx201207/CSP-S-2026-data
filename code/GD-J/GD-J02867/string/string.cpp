#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string a, b;
	int n, l = 0, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int p;
		char q;
		cin >> p >> q;
		l += p;
		for (int j = 1; j <= p; j++){
			a += q;
		}
	}
	for (int i = 0; i < l/2; i++){
		if (a[i] != a[l-i+1]){ 
			cnt++;
		}
	}
	cout << cnt;
	return 0;
} 
