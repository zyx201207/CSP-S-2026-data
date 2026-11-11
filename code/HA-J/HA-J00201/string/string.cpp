#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 200005;
ll n, len = 0, cnt1 = 1, cnt2 = 0;
string s, s1;
string ss, ss1;
int solve1() {
	if (len % 2 == 1) {
		ll mid = len / 2;
		for (ll i = 1; i < mid; i++) {
			if (s[mid - i] != s[mid + i]) {
				cnt1++; 
				s[mid + i] = s[mid - i];
			}
		}
	}
	else if (len % 2 == 0) {
		ll mid = (len - 1) / 2;
		if (s[mid] != s[mid + 1]) {
			cnt1++;
			s[mid + 1] = s[mid];
		}
		for (ll i = 1; i < mid; i++) {
			if (s[mid - i] != s[mid + 1 + i]) {
				cnt1++; 
				s[mid + 1 + i] = s[mid - i];
			}
		}
	}
	return cnt1;
}

int solve2() {
	for (ll i = 0; i < s.length(); i++) {
		if (ss[i] != ss1[i]) {
			cnt2++;
			ss1[i] == ss[i];
		}
	}
	return cnt2;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	ll a[N];
	char c[N];
	for (ll i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		len += a[i];
		for (ll j = 0; j < a[i]; j++) s += c[i];
	} 
	for (ll i = s.length() - 1; i >= 0; i--) {
		s1 += s[i];
	}
	ss += s;
	ss1 += s1;
	if (s == s1) {
		cout << 0;
		return 0;
	}
	solve1();
	solve2();
	cout << min(cnt1, cnt2) << endl;
	return 0;
}
