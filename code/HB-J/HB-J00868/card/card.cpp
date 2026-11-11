#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005, MAXM = 300005;
int n, m, a[MAXN], ans[MAXM];
bool exist[MAXM];
stack<int> pokers;

bool issorted() {
    if (n == 1) return true;
    bool flag = false;
    for (int i = 1; i < n; ++i)
        if (a[i] > a[i + 1]) return false;
    return true;
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    if (issorted()) {
        for (int i = m; i >= 1; --i) cout << i << ' ';
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        memset(exist, 0, sizeof(exist));
        for (int j = i; j <= n; ++j) {
            stack<int> pokers;
            if (!exist[a[j]]) {
                pokers.push(a[i]);
                exist[i] = true;
            } else {
                while (pokers.top() != a[i]) {
                    exist[pokers.top()] = false;
                    pokers.pop();
                }
            }
        }
        if (exist[i]) ++ans[i];
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';

    return 0;
}
