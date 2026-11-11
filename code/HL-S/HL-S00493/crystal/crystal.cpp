#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[500001], b[500001];

queue<int> q, qq;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
	}
	q.push(1);
	ll used = 0, ans = 0;
	for (int i = 2; i <= n; i++) {
		if (used + b[i] * (i - q.front()) > m && !q.empty()) {	
			used -= (a[i - 1] - a[q.front()]);
			used += b[i] * (i - q.front() - 1); 
			q.pop();
			q.push(i);	
		} else {
			used += b[i] * (i - q.front());
			q.push(i);
			ans++;
		}
	}
//	while (!q.empty()) {
//		cout << a[q.front()] << " ";
//		q.pop();
//	}
	cout << ans + 1;
	return 0;
}
