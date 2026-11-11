#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin ("string.in");
ofstream fout ("string.out");
#define cin fin
#define cout fout

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	cin >> n;
	
	string s;
	while (n--) {
		ll a;
		string c;
		cin >> a >> c;
		for (ll i = 0; i < a; i++) s = s + c;
	}
	
	string s1, s2;
	if (s.size() % 2 == 0) {
		for (ll i = 0; i < s.size() / 2; i++) s1 += s[i];
		for (ll i = s.size() / 2 - 1; i < s.size(); i++) s2 += s[i];
	} else {
		for (ll i = 0; i < s.size() / 2; i++) s1 += s[i];
		for (ll i = s.size() / 2; i < s.size(); i++) s2 += s[i];
	}
	
	ll ans = 0;
	for (ll i = 0; i < s1.size(); i++) if (s1[i] != s2[s2.size() - i - 1]) ans++;
	cout << ans;
	
	return 0;
}
