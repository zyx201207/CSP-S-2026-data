#include <bits/stdc++.h>
using namespace std;

int c, t, u[1000010], v[1000010];

int main() {

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    int m = t;
    while(m--) {
        int n, k;
        cin >> n >> k;
        for(int i=0; i<n-1; i++) cin >> u[i] >> v[i];
        cout << t-m << endl;
    }

    return 0;
}
