#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long a[200001];
string s[200001];
vector<long long> f;

int cmp(const int x, const int y) {
	return x > y;
}

string to_two(const int mx, long long x) {
	string str = "", rts = "";
	int cnt = 0;
	if (mx == -1) {
		while (x > 0) {
			str += (x % 2 + '0');
			x /= 2;
			++ cnt;
		}
	}
	else {
		while (cnt < mx) {
			str += (x % 2 + '0');
			x /= 2;
			++ cnt;
		}
	}
	
	for (int i = str.size() - 1; i >= 0; i --) {
		rts += str[i];
	}
	return rts;
}

void solve() {
	long long ans = 0;
	s[1] = to_two(-1, a[1]);
	long long mx = s[1].size();
	for (int i = 2; i <= n; i ++) {
		s[i] = to_two(mx, a[i]);
	}
	for (int i = 0; i < mx; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (s[j][i] == '1') {
				f.push_back(j);
			}
		}
		if (f.size() >= m) {
			ans = a[f[0]];
			for (int i = 1; i < m; i ++) {
				ans &= a[f[i]];
			}
			cout << ans << endl;
			return ;
		}
		f.clear();
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	solve();
	return 0;
}
