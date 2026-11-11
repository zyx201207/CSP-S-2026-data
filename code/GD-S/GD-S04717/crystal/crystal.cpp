#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main (){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	int ans = 0, x = 0;
	for (int i = 2; i <= n; i++){
		int sum = 0;
		for (int j = 1; j < i; j++){
			sum += a[i] - a[j];
		}
		x = max(x, sum);
		if (x > m){
			ans = i-1;
			break;
		}
	}
	if (ans == 0){
		ans = n;
	}
	cout << ans;
}
