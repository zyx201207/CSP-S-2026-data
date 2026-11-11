#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, a[500005], sum[500005], m, ans;

int search(int l, int r, int bsc) {
    if(l >= r) return bsc - l + 1;
    int mid = (l + r) / 2;
    int ned = a[bsc] * (bsc - mid + 1) - (sum[bsc] - sum[mid - 1]);
    if(ned <= m) return search(l, mid, bsc);
    else return search(mid + 1, r, bsc);
}

signed main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= n; i++) {
        ans = max(ans, search(1, i, i));
    }
    cout << ans;

    return 0;
}