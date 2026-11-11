#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 10;
int n, m;
int a[N];
bool flag;
int cnt[N];
int ans[N];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < a[i - 1]) flag = 1;
        cnt[a[i]] = i;
    }
    if (m == 1) {
        cout << n << "\n";
        return ;
    }
    if (flag == 0) {
        for (int i = 1; i <= m; i++) {
            cout << cnt[i] << " ";
        }
        return ;
    }
    for (int i = 1; i <= n; i++) {
        int j = i, k = i;
        ans[i]++;
        for (; j <= k, k <= n; k++) {
            if (a[j] == a[k]) {
                j = k;
            }
        }
        for (int l = j; l <= k; l++) {
            ans[l]++;
        }
    }
    for (int i = 1; i < m; i++) cout << ans[i] << " ";
    cout << n;
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
