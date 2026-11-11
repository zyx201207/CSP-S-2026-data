#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
vector<int> b;
int ans;
void dfs(int idx) {
    if(idx >= n) {
        if(b.size() == m) {
            int res = b[0];
            for(int i = 1; i < m; i++) {
                res &= b[i];
            }
            ans = max(ans, res);
        }
        return;
    }
    dfs(idx + 1);
    b.push_back(a[idx]);
    dfs(idx + 1);
    b.pop_back();
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = a[0];
    int maxn = a[0];
    for(int i = 1; i < n; i++) {
        sum &= a[i];
        maxn = max(maxn, a[i]);
    }
    if(n == m) {
        cout << sum << endl;
        return 0;
    }
    if(m == 1) {
        cout << maxn << endl;
        return 0;
    }
    if(m == 2) {
        int mx = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                mx = max(mx, a[i] & a[j]);
            }
        }
        cout << mx << endl;
        return 0;
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}