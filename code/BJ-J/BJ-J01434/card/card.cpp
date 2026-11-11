#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int a[N], b[N];
bool c[N];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool fa = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] > a[i]) {
            fa = 0;
            break;
        }
    }
    if (fa) {
        for (int i = 2; i <= n + 1; i++) {
            if (a[i] != a[i - 1]) b[a[i - 1]] += i - 1;
        }
        for (int i = 1; i <= m; i++) cout << b[i] << ' ';
        return 0;
    }
    stack<int> s;
    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= m; i++) c[i] = 0;
        for (int i = t; i <= n; i++) {
            if (c[a[i]]) {
                while (s.size() && s.top() != a[i]) c[s.top()] = 0, s.pop();
                while (s.size() && s.top() == a[i]) c[s.top()] = 0, s.pop();
            }
            s.push(a[i]);
            c[a[i]] = 1;
        }
        while (s.size()) b[s.top()]++, s.pop();
    }
    for (int i = 1; i <= m; i++) cout << b[i] << ' ';
    cout << "\n";
    return 0;
}