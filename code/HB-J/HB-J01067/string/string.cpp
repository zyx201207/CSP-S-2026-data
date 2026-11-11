#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, l;
string s;
char ch;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l >> ch;
        for (int j = 1; j <= l; j++) s += ch;
    }
    ll sz = s.length(), ans = 0;
    s = '#' + s;
    for (int i = 1; i <= (sz >> 1); i++)   
        if (s[i] != s[sz - i + 1]) ans++;
    cout << ans << '\n'; 
    return 0;
}