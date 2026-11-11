#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
const int N = 5e5 + 5;
int n, a[N], m, s, ans;
priority_queue<int, vector<int>, greater<int> > q;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++){
		s += (a[i] - a[i - 1]) * q.size();
		q.push(a[i]);
		while (s > m){
			s -= a[i] - q.top();
			q.pop();
		}
		ans = max(ans, (LL)q.size());
	}
	printf("%lld", ans);
	return 0;
}
