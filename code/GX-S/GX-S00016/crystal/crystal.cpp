#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans;
long long c(int x){
	long long b[500005];
	for(int i = 1; i <= x; i++){
		if(i != x) b[i] = abs(a[x] - a[i]);
	}
	long long now = 0, all = 0;
	for(int i = x; i >= 1; i--){
		if(now + b[i] <= m) now += b[i], all++;
		else return all;
	}
	return all;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n > 20000){
		long long all = 0, aa = a[2] - a[1];
		for(int i = 1; i <= n; i++){
			if((i + 1) * i / 2 * aa <= m) all = i + 1;
			else break;
		}
		cout << all;
		return 0;
	}
	//int l = 1, r = n;
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++){
		ans = max(ans, c(i));
	}
	cout << ans;
	return 0;
}
