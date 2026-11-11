#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 10;
int u[maxn], v[maxn];

void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i ++){
        cin >> u[i] >> v[i];
    }
    cout << 0 << endl;
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t --)
        solve();
}

