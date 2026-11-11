#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e9 + 5;
int n;
ll l = 0,ans = 0;
ll a[20006];
char s[MAXN],c[20006];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 0;i <= n;i++) {
        cin >> a[i] >> c[i];
        for (int j = 0;j < a[i];i++) {
            l += 1;
            s[l] = c[i];
        }
    }
    for (ll i = 0;i < l / 2;i++) {
        if (s[i] == s[l + 1 - i]) continue;
        ans += 1;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}