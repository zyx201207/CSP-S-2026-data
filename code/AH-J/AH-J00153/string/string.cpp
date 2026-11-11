# include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll ans;
string s , s1 , s2;
int main () {
    freopen ("string.in" , "r" , stdin);
    freopen ("string.out" , "w" , stdout);
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    cin >> n;
    for (int i = 1;i <=  n;i ++) {
        ll a;
        char c;
        cin >> a >> c;
        s += string (a , c);
    }
    s1 = s.substr (0 , ll (s.size ()) / 2);
    s2 = s.substr ((ll (s.size ()) + 1) / 2 , ll (s.size ()) / 2);
    reverse (s2.begin () , s2.end ());
    for (ll i = 0;i < ll (s1.size ());i ++) {
        if (s1[i] != s2[i]) ans ++;
    }
    cout << ans;
    return 0;
}
