#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 2e5 + 10, E = INT_MAX;;

int n, m, ans = E, a[maxn];
int dp[maxn];

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= m; i++){
		if(n - i + 1 > 0)ans &= a[n - i + 1];
	}
	cout << ans;
	
	return 0;
}
