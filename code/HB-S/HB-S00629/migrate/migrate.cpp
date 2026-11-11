#include "bits/stdc++.h"
using namespace std;
int c, t, n;
long long d, x[2000005];
int main() {
    cin >> c >> t;
    while (t--) {
        memset(x, 0, sizeof(x));
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
    }
    return 0;
}