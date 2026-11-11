#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, ans = 1;
long long m, a[N], sum = 0;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int cnt = 1, k = a[1];
	for(int i = 2; i <= n; ++i){
		long long x = cnt * (a[i] - k);
		if(m >= x) {m -= x; ans++; cnt++; k = a[i];}
		else break;
	}
	cout << ans;
	return 0;
} 
