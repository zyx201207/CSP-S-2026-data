#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; long long m;
	cin >> n >> m;
	vector<long long> a(n);
	
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sort(a.begin(), a.end());
	
	int ans = 0;
	long long cost = 0;
	int num = 0;
	long long last = 0;
	
	for (int i = 0, first = 1, bound = 0; i < n; i++) {
		int j = i;
		while (j < n && a[i] == a[j]) j++;
		
		int cnt = j - i;
		
		if (first) ans = num = cnt, first = 0;
		else {
			long long ncost = a[i] - last;

			long long quota = m - cost;
			long long ok = min((long long)num, quota / ncost);
			
			while (ok < num && bound < i) {
				cost -= last - a[bound];
				num--;
				quota = m - cost;
				ok = min((long long)num, quota / ncost);
				
				bound++;
			}
//			debug("ncost = %d, quota = %d, ok = %d, cost = %d\n", ncost, quota, ok, cost);
//			debug("bound move to %d\n", bound);
			cost += ncost * ok;
			num = ok + cnt;
//			debug("if we fix the target at %d, the num is %d\n\n", a[i], num);
			ans = max(ans, num);
		}
		
		last = a[i];

		i = j - 1;
	}
	
	cout << ans << "\n";
	return 0;
}
