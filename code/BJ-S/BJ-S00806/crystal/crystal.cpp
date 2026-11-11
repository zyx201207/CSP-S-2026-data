#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n, ans = 1;
ll m, a[N], c[5010][5010];  //i:n, j:cha
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> a[1] >> a[2];
    ll d = a[2] - a[1];
    bool flag = true;
    for (int i = 3; i <= n; i++) {
        cin >> a[i];
        if (a[i] - a[i - 1] != d)
            flag = false;
    }
    sort(a + 1, a + 1 + n);
    if (flag == true) {
        ll cnt = 0;
        while(((cnt + d * ans) <= m) && (ans < n)) {
            cnt += d * ans;
            ans++;
        }
        cout << ans << endl;
        return 0;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = abs(a[i] - a[j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(c[i] + 1, c[i] + 1 + n);
    }
    int cntn = 1;
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        int j = 1;
        cnt = 0, cntn = 0;
        while (cnt + c[i][j] <= m && ++cntn <= n && j <= n) {
            cnt += c[i][j];
            j++;
        }
        ans = max(ans, cntn);
    }
    cout << ans << endl;
    return 0;
}
