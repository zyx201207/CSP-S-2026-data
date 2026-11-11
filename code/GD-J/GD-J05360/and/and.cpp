#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 2e5 + 10;
int n, m;
int a[MAX];
//ll dp[MAX][MAX];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	cout << a[n - m + 1];
	return 0;
}
