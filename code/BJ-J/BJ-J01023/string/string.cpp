#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n; string a; cin >> n;
    for (int i = 0; i < n; ++i) {
        int j; cin >> j;
        string c; cin >> c;
        for (int x = 0; x < j; x++) a += c;
    } int len = a.size();
    bool ov= false; if (len % 2 == 0) ov = true;
    string b, c; int ans = 0;
    for (int i = 0; i < (ov ? len/2 : len/2 - 1);++i) {
        if (a[i] != a[len-1-i]) ans++;
    } cout << ans;
}
