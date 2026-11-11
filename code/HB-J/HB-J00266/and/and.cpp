#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int n, m, ans;
int a[N];
bool vis[N];
vector<int> v;
bool sp1=true, sp2=true, sp3 = true;

void dfs(int cur) {
    if (v.size() == m) {
        ans = max(ans, cur);
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        v.push_back(a[i]);
        dfs(v.size() == 1? a[i]: cur & a[i]);
        vis[i] = false;
        v.pop_back();
    }
}

bool f(int x) {
    while (x) {
        if (!(x&1)) return false;
        x >>= 1;
    }
    return true;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != i-1) sp1 = false;
        if (!f(a[i])) sp2 = false;
        if (a[i] >= 4) sp3 = false;
    }
    if (sp2) {
        sort(a+1, a+n+1);
        cout << a[m];
        return 0;
    }
    if (sp1) {
        cout << n-m;
        return 0;
    }
    if (sp3) {
        sort(a+1, a+n+1, cmp);
        ans = a[1];
        for (int i = 2; i <= m; i++) ans &= a[i];
        cout << ans;
        return 0;
    }
    dfs(0);
    cout << ans;
    return 0;
}
