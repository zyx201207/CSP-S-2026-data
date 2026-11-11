#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	long long num[200005], maxn = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		cin >> num[i];
		if (num[i] > maxn) maxn = num[i];
	}
	if (m == 1) cout << maxn;
	else if (m == n){
		int ans = num[1];
		for (int i = 2; i <= n; ++i){
			ans &= num[i];
		}
		cout << ans;
	}
	return 0;
}
