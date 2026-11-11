#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 2e5 + 5;
long long a[maxn];
long long ans = 0;
void dfs(int u, int v, long long sum) {
    if (v == m) {
        ans = max(ans, sum);
        return ;
    }
	if (u == n + 1) return ;
    dfs(u + 1, v + 1, sum & a[u]);
    dfs(u + 1, v, sum);
}
inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c > '9' || c < '0') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x * f;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    dfs(1, 0, 1073741823);
    cout << ans;
    return 0;
}
