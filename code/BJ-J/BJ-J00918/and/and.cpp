#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N];
int vis[N];
int mx;
int n, m;

void dfs(int dep, int val) {
    if(dep == m) {
        mx = max(mx, val);
        return;
    }
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(dep + 1, val & a[i]);
            vis[i] = 0;
        }
    }
}

int pow2(int a) {
    if(a == 0) return 1;
    return 2 * pow2(a - 1);
}
int powers[50];

int main() {

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
            cin >> a[i];
    }
    for(int i = 0; i <= 30; i ++) powers[i] = pow2(i);

    if(m == n) {
        int ans = a[1];
        for(int i = 2; i <= n; i ++) ans &= a[i];
        cout << ans;
        return 0;
    }
    if(log2(n) - floor(log2(n)) <= 0.0001 || log2(n) - floor(log2(n)) > 0.9999) {
        bool flag = true;
        for(int i = 1; i <= n; i ++) if(a[i] != i - 1) flag = false;
        if(flag) {
            int ans = a[n];
            for(int i = n - 1; i >= n - m + 1; i --) {
                ans &= a[i];
            }
            cout << ans;
            return 0;
        }
    }
    bool flag = true;
    for(int i = 1; i <= n; i ++) {
        bool flag2 = false;
        for(int j = 0; j <= 30; j ++) {
            if(a[i] == powers[j]) {
                flag2 = true;
            }
        }
        if(!flag2) {
            flag = false;
            break;
        }
    }

    if(flag) {
        sort(a + 1, a + n + 1);
        cout << a[n - m + 1];
    }

    dfs(0, INT_MAX);

    cout << mx;

    return 0;
}
