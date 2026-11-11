#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n, m, ans = INT_MIN, i;
ll a[N];
priority_queue<ll> q; 
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		q.push(a[i]);
	}
	ans = q.top();
	q.pop();
	for (i = 2; i <= m; i++){
		ans = ans & q.top();
		q.pop();
	}
	printf("%lld", ans);
	return 0;
} 
