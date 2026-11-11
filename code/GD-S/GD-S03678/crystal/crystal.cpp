
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 30;
long long a[N], m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a+1, a+1+n);
	
	deque<long long> q;
	int qcnt = m, ans = 0;
	
	for (int i = n; i > 0; i--) {
		q.push_front(a[i]); 
		qcnt -= q.back() - a[i];
		while(q.size() && qcnt < 0) {
			long long last = q.back();
			q.pop_back(); 
			if (q.size()) qcnt += q.size() * (last - q.back());
		}
		ans = max(ans, (int)q.size());
	}
	
	cout << ans;
	
	return 0;
}
