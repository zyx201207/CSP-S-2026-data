#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a[500010];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int o = a[n/2];
    cout << o << endl;


    return 0;
}
