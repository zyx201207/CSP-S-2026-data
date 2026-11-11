#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], ans, cnt;
queue<int> q;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		while(!q.empty() && cnt + (int)(q.size()) * (a[i] - a[i - 1]) > m){
			cnt -= (a[i - 1] - a[q.front()]), q.pop();
		}
		cnt += q.size() * (a[i] - a[i - 1]);
		q.push(i);
		ans = max(ans, (int)(q.size()));
	}
	printf("%lld\n", ans);
	return 0;
} 
