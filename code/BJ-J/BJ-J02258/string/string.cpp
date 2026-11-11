#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans, cnt, a[200010];
char c[200010];
string s;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        for(int j = 1; j <= a[i]; j++) s[cnt++] = c[i];
    }
    for(int i = 0; i < cnt / 2; i++) if(s[i] != s[n - i]) ans++;
    cout << ans;
    return 0;
}
