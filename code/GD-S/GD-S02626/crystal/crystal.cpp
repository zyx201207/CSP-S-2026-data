#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 9;
ll n, m, a[N], dp[N];int ans = 1;
queue <ll> q;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	dp[1] = 0;
	q.push(1);
	for (int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + (a[i] - a[i - 1]) * (i - 1);
		q.push(i);
		while (dp[i] > m){
			int f = q.front();
			q.pop();
			dp[i] -= a[i] - a[f];
		}
		ans = max(ans, int(q.size()));
	}
	cout << ans;
	return 0;
}
