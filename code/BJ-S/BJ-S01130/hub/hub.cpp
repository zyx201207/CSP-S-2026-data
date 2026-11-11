#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define pii pair < int , int >
#define mp(i, j) make_pair(i, j)

// 细节题 需要好好实现
const int N = 2e6 + 5;
ll n, m, a[N], d, nxt[N], vis[N], cl[N];

void solvetask() {
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
    }
    cout << n - m << "\n";
    return;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    int c, T = 1;
    cin >> c >> T;
    while(T --) solvetask();
    return 0;
}
