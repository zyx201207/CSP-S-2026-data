#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAXN = 2e5 + 5; 
ll n, a, ans = 0;
string s;
char c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a >> c;
		while (a--) s += c;
	}
	
	ll mid = s.size() / 2;
	ll len = s.size();
	for (ll i = mid, j = mid; i >= 0 && j < len; i--, j++) {
		if (s[i] != s[j]) ans++;
	}
	
	cout << ans << endl;
	return 0;
}

