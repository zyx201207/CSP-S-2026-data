#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
vector <int> f[M];
int n, m, a[N], ans[M];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i >= 1; i--)  {
        if(f[a[i]].size() == 0) {
            f[a[i]] = f[a[i + 1]];
            f[a[i]].push_back(a[i]);
        }
        for(int j : f[a[i]]) ans[j]++;
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}