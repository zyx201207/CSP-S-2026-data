#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100010];
int maxn;
vector<int>b;

void dfs(int i, int sum) {
    if (sum == m) {
        int num = b[0];
        for (int i = 1; i < b.size(); i++) {
            num &= b[i];
        }
        maxn = max(maxn, num);
        return;
    }
    if (i > n) {
        return;
    }
    b.push_back(a[i]);
    dfs(i + 1, sum + 1);
    b.pop_back();
    dfs(i + 1, sum);
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << maxn;
    return 0;
}
