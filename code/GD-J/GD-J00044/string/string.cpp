#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5; 
int n, m, k, sum, cnt, a[N];
char c[N];
vector<pair<int, char>>v, v2, v3;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	int i, j, x, y, z, t;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i] >> c[i], sum += a[i];
	int len = sum / 2;
	for (i = 1; i <= n; i++) {
		cnt += a[i];
		if (cnt > len) {
			cnt -= a[i];
			v.push_back({len - cnt, c[i]});
			a[i] -= len - cnt;
			cnt = len;
			i--;
			break;
		}
		v.push_back({a[i], c[i]});
		if (cnt == len)
			break;
	}
	if (sum % 2 == 1)
		a[i + 1]--; 
	for (i = i + 1; i <= n; i++)
		v3.push_back({a[i], c[i]});
	for (i = v3.size() - 1; i >= 0; i--)
		v2.push_back({v3[i].first, v3[i].second}); 
	int l1 = v.size(), l2 = v2.size(), ans = 0;
	for (i = 0, j = 0; i < l1 && j < l2;) {
		if (v[i].first < v2[j].first) {
			if (v[i].second != v2[j].second)
				ans += v[i].first;
			v2[j].first -= v[i].first, i++;
		} else if (v2[j].first < v[i].first) {
			if (v[i].second != v2[j].second)
				ans += v2[j].first;
			v[i].first -= v2[j].first, j++;
		} else if (v[i].first == v2[j].first) {
			if (v[i].second != v2[j].second)
				ans += v[i].first;
			i++, j++;
		}
	}
	cout << ans;
	return 0;
}
