#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 5e5 + 5;

i64 n, m, a[N], s[N];

bool check(int len) {
    for (int i = len; i <= n; i++) {
        if (len * a[i] - (s[i] - s[i - len]) <= m) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = a[i] + s[i - 1];
    int l = 1, r = n + 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        check(mid) ? (l = mid) : (r = mid);
    }
    cout << l << "\n";
}