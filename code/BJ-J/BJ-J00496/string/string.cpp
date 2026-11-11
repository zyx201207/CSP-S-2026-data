#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005], ans;
char c[200005];
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    //vector<pair<int, char>> v;
    cin >> n;
    int l = 0;
    string s;
    cin >> a[1] >> c[1];
    s = c[1];
    for (int i = 2; i <= a[1]; i++) s += c[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i] >> c[i];
        for (int j = 1; j <= a[i]; j++) s += c[i];
    }
    int len = s.size();
    s = " " + s;
    for (int i = 1, j = len; i <= len/2; i++, j--) {
        if (s[i] != s[j]) {
            s[j] = s[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}
