#include <bits/stdc++.h>
#define int long long
using namespace std;
struct part {
    int start, end;
    char c;
};
vector<part> parts;
int n;
char get_chr(int idx) {
    int l = 0, r = parts.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (parts[mid].end >= idx) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (parts[l].start <= idx && idx <= parts[r].end) {
        return parts[l].c;
    } else {
        return '+';
    }
}
int len = 0;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int cur = 0;
    for (int i = 1, a; i <= n; i++) {
        char c;
        cin >> a >> c;
        len += a;
        parts.push_back({cur + 1, cur + a, c});
        cur += a;
    }
    int ans = 0;
    for (int i = 1; i <= len / 2; i++) {
        if (get_chr(i) != get_chr(len + 1 - i)) {
            ++ ans;
        }
    }
    cout << ans << "\n";
    return 0;
}
