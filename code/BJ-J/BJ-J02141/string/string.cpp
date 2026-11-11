#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], cnt;
char c[200005];
string s;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
        for (long long j = 1; j <= a[i]; ++j) {
            s += c[i];
        }
    }
    long long len = s.size();
    long long last = len - 1;
    for (long long i = 0; i < len / 2; ++i) {
        if (s[i] != s[last - i]) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}