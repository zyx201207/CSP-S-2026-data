#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;

int n, l = 1, r;
ll len, ans, a[N];
char c[N];
pair <ll, char> q, q2;

int main () {
	
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> a[i] >> c[i];
	}
	
	r = n;
	q = {a[1], c[1]};
	q2 = {a[n], c[n]};
	
	while (l < r) {
		if (q.second != q2.second) {
			if (q.first < q2.first) {
				ans += q.first;
				q2.first -= q.first;
				++l;
				q = {a[l], c[l]};
			} else if (q.first > q2.first) {
				ans += q2.first;
				q.first -= q2.first;
				--r;
				q2 = {a[r], c[r]};
			} else {
				ans += q.first;
				++l;
				--r;
				q = {a[l], c[l]};
				q2 = {a[r], c[r]};
			}
		} else {
			if (q.first < q2.first) {
				q2.first -=q.first;
				++l;
				q = {a[l], c[l]};
			} else if (q.first > q2.first) {
				q.first -= q2.first;
				--r;
				q2 = {a[r], c[r]};
			} else {
				++l;
				--r;
				q = {a[l], c[l]};
				q2 = {a[r], c[r]};
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
