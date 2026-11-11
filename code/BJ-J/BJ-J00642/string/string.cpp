#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005];
char c[200005];
string s;
int change(string s) {
    long long l = 0, r = s.size() - 1, ans = 0;
    while (l <= r) {
        if (s[l] != s[r]) ans++;
        l++, r--;
    }
    return ans;
}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        for (int j = 1; j <= a[i]; j++) s += c[i];
    }
    cout << change(s);
    return 0;
}
