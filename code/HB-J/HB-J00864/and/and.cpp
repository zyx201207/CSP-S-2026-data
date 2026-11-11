#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int n, m, ans = 0;
int start = (1 << 30) - 1;
vector<int> arr;

int cnt(int v) {
    int res = 0;
    while (v) {
        ++res;
        v &= v - 1;
    }
    return res;
}

void dfs(int d, int c, int cur) {
    if (n - d < m - c)
        return;
    if (ans >= cur && cnt(ans) >= cnt(cur))
        return;
    if (c == m) {
        ans = max(ans, cur);
        return;
    }
    dfs(d + 1, c, cur);
    dfs(d + 1, c + 1, cur & arr[d]);
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    arr.resize(n);
    bool isa = true, isless4 = true;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (((ll)arr[i] + 1) & (ll)arr[i])
            isa = false;
        if (arr[i] >= 4)
            isless4 = false;
    }
    if (isa) {
        sort(arr.begin(), arr.end());
        cout << arr[n - m];
        return 0;
    }
    if (isless4) {
        sort(arr.begin(), arr.end());
        int res = 3;
        for (int i = n - m; i < n; ++i)
            res &= arr[i];
        cout << res;
        return 0;
    }
    if (m == 1) {
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, arr[i]);
        cout << res;
        return 0;
    }
    if (m == n) {
        int res = arr[0];
        for (int i = 1; i < n; ++i)
            res &= arr[i];
        cout << res;
        return 0;
    }
    dfs(0, 0, start);
    cout << ans;
    return 0;
}