#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, ans;
long long m, a[N], sum[N];
long long w(int l, int r){
	return a[r] * (r - l + 1) - (sum[r] - sum[l - 1]);
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i){
		sum[i] = sum[i - 1] + a[i];
	}
	for (int r = 1, l = 1; r <= n; ++r){
		while(w(l, r) > m){
			++l;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
