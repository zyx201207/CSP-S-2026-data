#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, cnt, ans, l;
vector<pair<int, char>> s;
void ned(int x, char ch) {
	int len = s.back().first;
	char n_ch = s.back().second;
	if(len == x) {
		if(n_ch != ch) ans += x;
		s.pop_back();
		return;
	}
	if(len > x) {
		if(n_ch != ch) ans += x;
		s[s.size() - 1] = make_pair(len - x, n_ch);
		return;
	}
	if(n_ch != ch) ans += len;
	s.pop_back();
	ned(x - len, ch);
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin >> n;
	for(int i = 1, a; i <= n; ++ i) {
		char c;
		cin >> a >> c;
		s.emplace_back(a, c);
		l += a;
	}
	for(int i = 0; cnt < (l >> 1); ++ i) {
		if(cnt + s[i].first > (l >> 1)) {
			ned((l >> 1) - cnt, s[i].second);
			cnt = l >> 1;
		}
		else {
			ned(s[i].first, s[i].second);
			cnt += s[i].first;
		}
	}
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
