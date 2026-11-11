#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n;
string s;
ll cnt = 0;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll a0;
        char c0;
        cin >> a0 >> c0;
        while (a0--) s += c0;
    }
    ll l = s.size();
    s = " " + s;
    for (int i = 1; i * 2 < l; i++) 
        if (s[i] != s[l - i + 1]) cnt++;
    cout << cnt;
    return 0;
}