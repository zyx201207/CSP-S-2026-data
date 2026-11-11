#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int a[N];
char c[N];

struct node {
    mutable int a;
    char c;
};
stack<node> s;

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        s.push({a[i], c[i]});
    }
    for (int i = 1; i <= n; i++) {
        while (s.size() && a[i] > s.top().a) {
            a[i] -= s.top().a;
            if (s.top().c != c[i]) ans += s.top().a;
            s.pop();
        }
        if (s.size()) {
            if (c[i] != s.top().c) ans += a[i];
            s.top().a -= a[i]; 
        }
    }
    cout << ans / 2 << "\n";
    return 0;
}