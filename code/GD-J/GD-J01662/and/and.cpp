#include<bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long n, m, ans = INT_MIN;
long long a[N];
void dfs(long long x, long long sum, long long c){
	if (x > n) return ;
	if (c == m){
		ans = max(ans, sum);
		return ;
	}
	dfs(x + 1, sum & a[x + 1], c + 1);
	dfs(x + 1, sum, c);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (m == 1){
		for (long long i = 1; i <= n; i++) ans = max(ans, a[i]);
		cout << ans;
		return 0;
	} else if (m == n){
		long long cnt = a[1];
		for (long long i = 2; i <= n; i++) cnt &= a[i];
		cout << cnt;
		return 0;
	}
	for (long long i = 1; i <= n; i++){
		dfs(i, a[i], 1);
	}
	cout << ans;
	return 0;
}

