#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    long long c, t;
    long long n[c+10], d[c+10], x[1000010];

    for (int i = 1;i <= c; i++){
        cin >> n[i] >> d[i];
        for (int j = 1; j <= n[i]; j++) {
            cin >> x[j];
        }
    }

    for(int k = 1; k <= c; k++) {
        cout << x[k];
    }
    return 0;
}
