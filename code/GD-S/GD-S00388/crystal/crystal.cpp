#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long m, arr[500005];
long long sum[500005];

int ans = 1;

int fast_io = []() {
    cin.tie(0) -> sync_with_stdio(false);
    return 0;
}();

int file_io = []() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    return 0;
}();

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    } sort(arr + 1, arr + 1 + n);

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + arr[i];

        int l = 0, r = i;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if ((i - mid + 1) * arr[i] > sum[i] - sum[mid - 1] + m) l = mid;
            else r = mid;
        }

        ans = max(i - r + 1, ans);
    }

    cout << ans;
}