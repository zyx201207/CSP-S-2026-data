#include <bits/stdc++.h>
using namespace std;


int c, t, n, d;
int a[2000010];
long long ans;
vector<pair<int, int>> v; 
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &c, &t);
	while (t--) {
		ans = 0;
		scanf("%d %d", &n, &d);
		v.push_back({0, 0});
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (i >= 3 && a[i] - a[i - 2] <= d) {
				v.push_back({i - 2, i});
			}
		}
		v.push_back({n + 1, n + 1});
		for (int i = 2; i + 1 < v.size(); i++) {
			long long x = v[i - 1].first - v[i - 2].first;
			long long y = v[i + 1].second - v[i].second;
			ans += x * y;
//			cout << x << " " << y << endl;
			
		}
		printf("%lld\n", ans);
//		break;
	}
	return 0;
}
