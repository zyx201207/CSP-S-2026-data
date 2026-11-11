#include<bits/stdc++.h>
using namespace std;
struct Str{
	long long a;
	char c;
};
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<Str> s(n + 1);
	vector<long long> pre(n + 1);
	vector<long long> las(n + 1);
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].c;
		sum += s[i].a;
		pre[i] += s[i].a;
	}
	for (int i = n; i >= 1; i--) {
		las[i] += s[i].a;
	}
	long long mid = sum / 2;
	int l = 1, r = n;
	if (l == r) {
		cout << 0 << endl;
		return 0;
	}
	long long ans = 0;
	int l_diff = 0;
	int r_diff = 0;
	while (l <= r) {
		int lenl = s[l].a - l_diff;
		if (pre[l] > mid) {
			lenl = pre[l] - mid;
			lenl = s[l].a - lenl;
		}
		int lenr = s[r].a - r_diff;
		if (las[r] > mid) {
			lenr = las[r] - mid;
			lenr = s[r].a - lenr;
		}
		if (s[l].c != s[r].c) {
			if (lenl > lenr) {
				ans += lenr;
				l_diff += lenr;
				r_diff = 0;
				r--;
			}
			if (lenl < lenr) {
				ans += lenl;
				r_diff += lenl;
				l_diff = 0;
				l++; 
			}
			if (lenl == lenr) {
				ans += lenl;
				r_diff = 0;
				l_diff = 0;
				l++;
				r--;
			}
		} else {
			if (lenl > lenr) {
				l_diff += lenr;
				r_diff = 0;
				r--;
			}
			if (lenl < lenr) {
				r_diff += lenl;
				l_diff = 0;
				l++; 
			}
			if (lenl == lenr) {
				r_diff = 0;
				l_diff = 0;
				l++;
				r--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

