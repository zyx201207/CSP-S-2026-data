#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
long long a[N], ans;
void dfs(int k, int cnt, long long sum){
	if(cnt == m){
		ans = max(ans, sum);
		return;
	}
	if(n - k + 1 + cnt < m) return;
	if(k == n + 1) return;
	if(sum == -1) dfs(k + 1, cnt + 1, a[k]);
	else dfs(k + 1, cnt + 1, sum & a[k]);
	if(n + 1 - k + cnt > m) dfs(k + 1, cnt, sum);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(m == 1){
		cout << a[n] << endl;
		return 0;
	}
	if(m == 2 && n <= 1e5){
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				ans = max(ans, a[i] & a[j]);
		cout << ans << endl;
		return 0;
	}
	if(m == n){
		ans = a[1];
		for(int i = 2; i <= n; i++) ans &= a[i];
		cout << ans << endl;
		return 0;
	}
	if(n <= 2000){
		dfs(1, 0, -1);
		cout << ans << endl;
		return 0;
	}
	ans = a[n - m + 1];
	for(int i = n - m + 2; i <= n; i++) ans &= a[i];
	cout << ans << endl;
	return 0;
}
