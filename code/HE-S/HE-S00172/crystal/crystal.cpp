#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int a[500005];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    int cnt = 0, sum = 0;
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        int x = (a[i] - a[i - 1]) * cnt;
        cnt++;
        while (x > m - sum) {
            sum -= a[i - 1];
            x -= a[i] = a[i - 1];
            cnt--;
        }
        sum += x;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
