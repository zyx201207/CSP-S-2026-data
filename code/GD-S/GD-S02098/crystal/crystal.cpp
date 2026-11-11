#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 5e5 + 7;
constexpr ll M = 1e18;
constexpr ll LFT = 1e12;

ll a[N];
ll c[N];
ll sum[N];
int n;
int mx = -1;
ll m;

bool check(int mid, int R) {
    return sum[R] - sum[mid - 1] <= m;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += LFT;
    }

    sort(a + 1, a + n + 1);

    for (int i = 2; i <= n; i++) {
        ll d = a[i] - a[i - 1];
        sum[i] = sum[i - 1] + d * (i - 1);
        // cout << d << " ";
    }

    // for (int i = 1; i <= n; i++) cout << sum[i] << " ";
    // cout << "\n";

    for (int r = 1; r <= n; r++) {
        int cnt = 0, res = m;
        int L = 1, R = r;
        int ans = 0;
        // cout << "### r: " << r << "\n";
        while (L <= R) {
            int mid = L + R >> 1;
            // cout << val << " " << L << " " << R << " " << mid << "\n";
            if(check(mid, r)) {
                ans = mid;
                R = mid - 1;
            } else L = mid + 1;
        }
        // cout << R << "\n";
        // cout << ans << "\n";
        if (ans == 0) continue;
        cnt = r - ans + 1;
        mx = max(cnt, mx);
    }

    cout << mx << "\n";


    return 0;
}


/*

5 5 
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
