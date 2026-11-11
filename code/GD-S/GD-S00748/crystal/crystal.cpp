#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n;
long long m, a[N], pre[N];

bool check(int l, int r) {
    return a[r] * (r - l + 1) - (pre[r] - pre[l - 1]) <= m; 
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, pos = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid, i)) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - pos + 1);
    }
    return cout << ans, 0;
}