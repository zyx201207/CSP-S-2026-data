#include <bits/stdc++.h>
#define ll long long
#define FILE(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;

const int N = 500100;

int n;
ll m;
ll A[N], suf_sum[N];

int main() {
    FILE("crystal");
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> A[i];
    sort(A + 1, A + n + 1);
    for(int i = n; i >= 1; i--) suf_sum[i] = suf_sum[i + 1] + A[i];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while(l < r) {
            int mid = l + r >> 1;
            if((i - mid + 1ll) * A[i] - suf_sum[mid] + suf_sum[i + 1] <= m) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << '\n';
    return 0;
}