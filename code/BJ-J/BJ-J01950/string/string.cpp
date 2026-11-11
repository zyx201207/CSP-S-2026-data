#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
string s, t;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; string c;
        cin >> x >> c;
        for (int j = 1; j <= x; j++) s += c;
    }
    int l = s.size();
    for (int i = l - 1; i >= 0; i--)
        t += s[i];
    for (int i = 0; i < l / 2; i++)
        if (t[i] != s[i]) ++ans;
    cout << ans << endl;
    return 0;
}
