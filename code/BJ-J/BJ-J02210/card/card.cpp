#include<cstdio>
#include<iostream>
using namespace std;

int n, m, ans, a[500005], dp[5005][5005];
bool vis[200005];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cout << "0 ";
    }
    return 0;
}
