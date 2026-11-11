#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;

constexpr int MAXN = 2e5 + 10;

ll a[MAXN], pre[MAXN], suf[MAXN];
int n;
char ch[MAXN];
vector<pair<ll, char>> s, t;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	ll sum = 0;
	for (register int i = 1; i <= n; ++i) cin >> a[i] >> ch[i], sum += a[i], pre[i] = pre[i - 1] + a[i];
	for (register int i = n; i; --i) suf[i] = sum - pre[i - 1];
	ll mid = sum / 2, ans = 0;
	int pos = 1;
	for (; pre[pos] <= mid; ++pos);
	for (register int i = 1; i < pos; ++i) s.emplace_back(a[i], ch[i]);
	if (mid != pre[pos - 1]) s.emplace_back(mid - pre[pos - 1], ch[pos]);
	for (register int i = n; i > pos; --i) t.emplace_back(a[i], ch[i]);
	if (mid != suf[pos + 1]) t.emplace_back(mid - suf[pos + 1], ch[pos]);
	int lst = 0, m = s.size(), k = t.size();
	
	for (register int i = 0; i < m; ++i) {
		ll tmp1 = s[i].first;
		char tmp2 = s[i].second;
		
		while (lst < k && tmp1 > 0) {
			if (tmp2 != t[lst].second) ans += min(t[lst].first, tmp1);
			if (tmp1 <= t[lst].first) {
				if (tmp1 == t[lst].first) ++lst;
				else t[lst].first -= tmp1;
				break;
			}
			tmp1 -= t[lst].first, ++lst;
		}
	}
	
	cout << ans; 
	return 0;
}
