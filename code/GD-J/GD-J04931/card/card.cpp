#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
long long cnt[N];
long long x[N];
stack<int> a, b;

int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	long long n, m;
	cin >> n >> m;
	for (long long i = n; i >= 1; i--) cin >> x[i];
	
	while (n) {
		for (long long i = 1; i <= n; i++) a.push(x[i]);
		n--;
		
		while (!a.empty()) {
			b.push(a.top());
			a.pop();
		}
		
		while (!b.empty()) {
			cnt[b.top()]++;
			b.pop();
		}
		
	}
	
	for (long long i = 1; i < m; i++) cout << cnt[i]-1 << " ";
	cout<<cnt[m];
	
	return 0;
}
