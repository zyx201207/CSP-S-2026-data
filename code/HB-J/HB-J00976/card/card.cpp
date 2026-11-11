#include <bits/stdc++.h>
using namespace std;

int n, m;
constexpr int maxn = 500000 + 5;
constexpr int maxm = 300000 + 5;
int a[maxn];
int ans[maxm];
bool vis[maxm];

int s[maxn];
int top = 0;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        top = 0;
        for (int j = i; j < n; j++) {
            if (vis[a[j]]) {
                while (s[top - 1] != a[j]) {
                    vis[s[top - 1]] = 0;
                    top--;
                }
                top--;
            }
            s[top++] = a[j];
            vis[a[j]] = true;
        }
        for (int i = 1; i <= m; i++)
            ans[i] += vis[i], vis[i] = 0;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}