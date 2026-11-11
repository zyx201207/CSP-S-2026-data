#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll cnt, l, len;
string s;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--) {
        int a; char c;
        cin >> a >> c;
        for (int i = 1; i <= a; i++) s += c, l++;
    }
    if (l % 2 == 0) len = l / 2;
    else len = l / 2 + 1;
    for (int i = 0; i < len; i++) {
        if (s[i] != s[l - i - 1]) {
            s[i] = s[l - i - 1];
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
