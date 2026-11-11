#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 201000;
pair<int, char> a[N];
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %c", &a[i].first, &a[i].second);
		sum += a[i].first;
	}
	vector<pair<ll, char>> b;
	for (int i = 1; i <= n; i++) {
		int j = i;
		ll s = a[i].first;
		while (j < n && a[j + 1].second == a[i].second) {
			++j;
			s += a[j].first;
		}
		b.push_back(make_pair(s, a[i].second));
		i = j;
	}
	int len = b.size();
	ll t = 0;
	int pos = -1;
	for (int i = 0; i < len; i++) {
		t += b[i].first;
		if (t >= sum / 2) {
			pos = i;
			break;
		}
	}
	if (t > sum / 2) {
		b.insert(b.begin() + pos + 1, make_pair(t - sum / 2, b[pos].second));
		len++;
	}
	if (sum % 2 == 1) {
		b[pos + 1].first -= 1;
	}
	b[pos].first -= t - sum / 2;
	vector<pair<ll, char>> c;
	for (int i = pos + 1; i < len; i++) {
		c.push_back(b[i]);
	}
	reverse(c.begin(), c.end());
	b.erase(b.begin() + pos + 1, b.end());
	ll ans = 0;
	ll j = -1, p = 0, s = 0;
	int m = b.size(), q = c.size();
	for (int i = 0; i < m; i++) {
		if (p > s && c[j].second != b[i].second) {
			ans += min(p, s + b[i].first) - s;
		}
		s += b[i].first;
		while (j < q - 1 && p < s) {
			++j;
			if (c[j].second != b[i].second) {
				ans += min(s, p + c[j].first) - p;
			}
			p += c[j].first;
		}
	}
	printf("%lld\n", ans);
	return 0;
}