#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main() {
    ll T;
    freopen("string.in", "in", stdin);
    freopen("string.out", "out", stdout);
    cin >> T;
    string s;
    ll j = 1;
    while (T--) {
        ll n;
        char c;
        cin >> n >> c;
        for (ll i = 1; i <= n; i++) {
            s[j] = c;
            j++;
        }
    }
    ll count = 0, i = 1;
    while (i <= j) {
        if (s[i] != s[j]) {
            s[i] = s[j];
            count++;
        }
        i++, j--;
    }
    cout << count;
}
