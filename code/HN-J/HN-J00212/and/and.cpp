#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], pre[N], ans;
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = n, tmp; i > m; i--){
		tmp = a[i];
		for(int j = i; j >= i - m + 1; j--) tmp &= a[j];
		ans = max(ans, tmp);
	}
	cout << ans;
	return 0;
} 

