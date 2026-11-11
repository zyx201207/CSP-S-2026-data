#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
const int N = 5e5 + 5;
int n, ans = 1;
long long m, a[N], sum[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	FILE("crystal")
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
		while (ans < i && (ans + 1) * a[i] - (sum[i] - sum[i - ans - 1]) <= m){
			ans++;
		}
	}
	cout << ans;
	return 0;
}

