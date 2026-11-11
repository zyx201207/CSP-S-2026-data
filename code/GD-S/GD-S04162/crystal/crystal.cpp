#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 10; 

queue<int> q;
int n, m, sum, ans, a[N];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; ++i) {
		sum += a[i], q.push(a[i]);
		
		while (!q.empty() && q.size() * a[i] - sum > m) {
			sum -= q.front();
			q.pop();
		}
		
		ans = max(ans, (long long)q.size());
	} 
	
	cout << ans << '\n';
	return 0;
}
