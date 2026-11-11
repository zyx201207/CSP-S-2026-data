#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N], c[N], need[N];
map<long long, long long> mp;
long long n, m;

int main () {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	long long ans = 1;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
		mp[a[i]] ++;
		ans = max(ans, mp[a[i]]);
	}
	sort (a + 1, a + n + 1);
	for (int i = 1;i <= n;i ++) {
		c[i] = a[i + 1] - a[i];
	}
	a[n + 1] = 1e12 + 10;
	long long nd = 0;
	long long s = 1, l = 1;
	for (int i = 1;i <= n;i ++) {
		nd = c[i] * (i - l + 1) + nd;
		for (int j = l;j <= i;j ++) {
			need[j] += c[i];
		}
		s ++;
		//cout << "nd:" << nd << endl;
		if (nd <= m) ans = max(ans, s);
		else {
			while (nd > m) {
				nd -= need[l];
				l ++;
				s --;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
