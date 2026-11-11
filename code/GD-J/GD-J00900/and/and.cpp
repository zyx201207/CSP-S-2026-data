#include <bits/stdc++.h>
using namespace std;
int a[200005];
int ton[10];
int ans;
int n, m;
vector <int> logs;
void dfs(int x, int cnt, int sum) {
	if(x > n) {
		if(cnt == m) {
			ans = max(ans, sum);
		}
		return;
	}
	dfs(x + 1, cnt + 1, (int)(sum & a[x]));
	dfs(x + 1, cnt, sum);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int maxa = 0;
	int sum = pow(2, 30) - 1;
	bool ok1 = 1;
	bool ok2 = 1;
	bool ok3 = 1;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(pow(2, log2(a[i] + 1)) - 1 != a[i]) ok1 = 0;
		else logs.push_back((int)log2(a[i] + 1));
		if(a[i] != i - 1) ok2 = 0;
		if(a[i] >= 4) ok3 = 0;
		else ton[a[i]] ++;
		maxa = max(maxa, a[i]);
		sum &= a[i];
	}
	if(m == n) {
		cout << sum;
	} else if(m == 1) {
		cout << maxa;
	} else if(ok1) {
		sort(logs.begin(), logs.end());
		cout << pow(2, logs[logs.size() - m]) - 1;
	} else if(ok2) {
		ans = n - 1;
		for(int i = n; i >= n - m + 1; i --) {
			ans &= a[i];
		}
		cout << ans;
	} else if(ok3) {
		if(ton[3] >= m) cout << 3;
		else if(ton[3] + ton[2] >= m) cout << 2;
		else if(ton[3] + ton[2] + ton[1] >= m) cout << 1;
		else cout << 0;
	} else if(n <= 20) {
		dfs(1, 0, pow(2, 30) - 1);
		cout << ans;
	} else if(m == 2) {
		for(int i = 1; i < n; i ++) {
			for(int j = i + 1; j <= n; j ++) {
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans;
	} else {
		dfs(1, 0, pow(2, 30) - 1);
		cout << ans;
	}
	return 0;
}
