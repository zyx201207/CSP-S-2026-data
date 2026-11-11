#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5+5;

ll n, a[N];
string s;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        char c;
        cin >> c;
        s += c;
    }

    string s1 = s;
    reverse(s1.begin(), s1.end());
    if(s1 == s) {
        cout << 0 << '\n';
        return 0;
    }

    ll len = s.size();
    ll ans = 0;
        for(ll i = 0; i <= len/2; ++i) {
            if(s[i] != s[len-i+1]) {
                s[i] = s[len-i+1];
                ans++;
            }
        }
    cout << ans << '\n';
    return 0;
}

