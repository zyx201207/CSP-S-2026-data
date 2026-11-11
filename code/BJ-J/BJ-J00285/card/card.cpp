#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], cnt[N];
bool vis[M];
stack <int> stk;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        while (stk.size()) stk.pop();
        for (int j = i; j <= n; j++) {
            if (vis[a[j]]) 
                while (stk.top() != a[j]) 
                    vis[stk.top()] = 0, stk.pop();
            else stk.push(a[j]), vis[a[j]] = 1;
        }
        for (int j = 1; j <= m; j++) cnt[j] += vis[j];
    }
    for (int i = 1; i <= m; i++) cout << cnt[i] << ' ';
    return 0;
}