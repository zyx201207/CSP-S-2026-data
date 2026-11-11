#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node {
	ll sum;
	char c;
} a[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	ll all_sum = 0, ans = 0;
	string s;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].sum >> a[i].c;
		for(int j = 1; j <= a[i].sum; j++) s += a[i].c;
		all_sum += a[i].sum;
	}
	if(all_sum & 1) {
		for(int l = 0, r = s.size() - 1; l < s.size() / 2, r > s.size() / 2; l++, r--) {
			if(s[l] != s[r]) ans++;
		}
	} else {
		for(int l = 0, r = s.size() - 1; l < s.size() / 2, r > s.size() / 2 + 1; l++, r--) {
			if(s[l] != s[r]) ans++;
		}
		if(s[s.size() / 2] != s[s.size() / 2 + 1]) ans++;
	}
	cout << ans;
	return 0;
}
