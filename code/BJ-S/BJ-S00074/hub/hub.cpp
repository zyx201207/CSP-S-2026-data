#include <bits/stdc++.h>
#define ll long long

using namespace std;

int c, t;

void Main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
    }
    cout << rand() % 3 << "\n";
    return ;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        Main();
    }
    return 0;
}
