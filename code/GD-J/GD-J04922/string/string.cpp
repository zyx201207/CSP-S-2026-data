#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
char c[200010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, f;
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> a[i] >> c[i];
		f += a[i] % 2;
		f %= 2;
	}
	int ans = 0;
	int i = 1, j = n;
	while (i <= j){
		if (i == j && f != a[i] % 2){
			ans ++;
			break;
		}
		if (c[i] != c[j]){
			ans += min(a[i], a[j]);
		}
		if (a[i] > a[j]){
			a[i] -= a[j];
			j --;
		}
		else if (a[i] < a[j]){
			a[j] -= a[i];
			i ++;
		}
		else if (a[i] == a[j]){
			i ++;
			j --;
		}
	}
	cout << ans << "\n";
	return 0;
}
