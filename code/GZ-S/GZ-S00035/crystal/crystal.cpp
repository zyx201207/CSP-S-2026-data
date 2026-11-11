// GZ-S00035 贵阳市白云区华师一学校 袁子高 
#include <bits/stdc++.h>
using namespace std;

using wint=long long;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	wint n, m;
	cin >> n >> m;
	vector<wint> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<wint> diff(n);
	diff[0] = 0;
	for (int i = 1; i < n; i++) {
		diff[i] = a[i] - a[i - 1];
	}
	wint l = 0, pre_sum = 0, m_sum = 0;
	wint max_len = 0;
	for (wint r = 0; r < n; r++) {
		pre_sum += diff[r];
		m_sum += diff[r] * (r - l);
		while (m_sum > m) {
			m_sum -= pre_sum;
			l++;
			pre_sum -= diff[l];
		}
		max_len = max(max_len, r - l + 1);
	}
	cout << max_len;
}

/*
15832 330750
*/
