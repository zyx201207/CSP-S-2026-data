#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, len, k, cnt;
string s;

ll read() {
    ll l = 0;
    int k = getchar();
    while ('0' > k || k > '9') {
    	k = getchar();
    } while ('0' <= k && k <= '9') {
    	l = l * 10 + (k - '0');
    	k = getchar();
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
    n = read();
    for (ll i = 0; i < n; ++i) {
    	ll a;
    	string c;
    	cin >> a >> c;
    	for (ll j = 0; j < a; ++j) {
    	    s += c;
    	}
    }
    len = s.size();
    k = len / 2;
    for (ll i = 0; i < k; ++i) {
     	if (s[i] != s[len - i]) {
     	    ++cnt;
     	}
    }
    cout << cnt;
    return 0;
}
