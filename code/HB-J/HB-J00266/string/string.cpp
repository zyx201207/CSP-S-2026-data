#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int n, lst;
long long ans;
string s;
int a[N];
char c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        while(a[i]--) s += c[i];
    }
    int m = s.length();
    for (int i = 0; i < m/2; i++) {
        if (s[i] != s[m-i-1]) ans++;
    }
    cout << ans;
    return 0;
}
