#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans;
priority_queue <ll>q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		ll a;
		cin >> a;
		q.push(a);
	}
	ans = q.top();q.pop();
	for(int i = 2; i <= m; i++) {
		ans &= q.top();
		q.pop();
	}
	cout << ans;
	return 0;
}
