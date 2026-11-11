#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
const int M = 1e5+5;

int n, m;
int a[N], ans[M];
vector<int> v;
set<int> s;

void solve(int st) {
    for (int i = st; i <= n; i++) {
        if (!s.count(a[i])) {
            v.push_back(a[i]);
            s.insert(a[i]);
        }
        else {
            s.clear();
            for (int j = 1; j <= n; j++) {
                s.insert(a[j]);
                if (a[j] == a[i]) {
                    v.resize(j);
                    break;
                }
            }
            v.push_back(a[i]);
            s.insert(a[i]);
        }
    }
    for (int i : v) ans[i]++;
    s.clear();
    v.clear();
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) solve(i);
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
