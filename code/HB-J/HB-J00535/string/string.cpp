#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll m;
string s;

void solve () {
    cin >> m;
    while (m--) {
        ll x;
        char c;
        cin >> x >> c;
        for (int i = 1; i <= x; i++)
            s.push_back (c);
    }
    ll cnt = 0;
    for (int i = 0; i < s.size () / 2; i++) {
        if (s[i] != s[s.size() - i - 1])
            cnt++;
    }
    cout << cnt << '\n';
}

int main () {
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);

    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    int T = 1; // cin >> T;
    while (T--) {
        solve ();
    }

    return 0;
}
