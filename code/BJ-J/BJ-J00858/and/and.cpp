#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, m, a[N], sum = 0;
vector <int> box;
void dfs(int d, int cnt) {
    if(n - d < cnt) return ;
    if(d >= n) {
        int s = a[box[0]];
        for(int i = 1; i < m; i ++ ) s = (s & a[box[i]]);
        sum = max(sum, s);
        return ;
    }
    box.push_back(d + 1);
    dfs(d + 1, cnt - 1);
    box.pop_back();
    dfs(d + 1, cnt);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        ans1 = max(ans1, a[n]);
        if(i == 1) ans2 = a[i];
        else ans2 = (ans2 & a[i]);
    }
    if(m == 1) {
        cout << ans1;
        return 0;
    }
    if(m == n) {
        cout << ans2;
        return 0;
    }
    if(m == 2) {
        int ans = 0;
        for(int i = 1; i < n; i ++ ) {
            for(int j = i + 1; j <= n; j ++ ) {
                ans = max(ans, (a[i] & a[j]));
            }
        }
        cout << ans;
        return 0;
    }
    else {
        dfs(0, m);
        cout << sum;
    }
    return 0;
}

