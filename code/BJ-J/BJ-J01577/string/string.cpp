#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int ln[200005], pre[200005], prec[200005][26], n;
char c[200005];
int query(int l, int r, char qc) {
    int rbound = lower_bound(pre + 1, pre + n + 1, r) - pre;
    int lbound = lower_bound(pre + 1, pre + n + 1, l) - pre;
    int res = 0;
    if (pre[lbound] >= l) {
        if (c[lbound] != qc) res += pre[lbound] - l + 1;
        lbound++;
    }
    if (pre[rbound] > r) {
        if (c[rbound] != qc) res += r - pre[rbound - 1];
        rbound--;
    }
    for (int i = 0; i < 26; i++) {
        if (i == qc - 'a') continue;
        res += prec[rbound][i] - prec[lbound - 1][i];
    }
    return res;
}
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ln[i] >> c[i];
        pre[i] = pre[i - 1] + ln[i];
        for (int j = 0; j < 26; j++) prec[i][j] = prec[i - 1][j];
        prec[i][c[i] - 'a'] += ln[i];
    }
    int len = pre[n], ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = pre[i - 1] + 1, r = pre[i];
        ans += query(len - r + 1, len - l + 1, c[i]);
        //if (pre[i] >= len / 2) break;
    }
    cout << ans / 2 << endl;
}
