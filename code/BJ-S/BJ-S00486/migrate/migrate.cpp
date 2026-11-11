

#include <bits/stdc++.h>

using namespace std;

int c,T,n, d, ans;
int x[5000009], f[5000009];

void Add(int s) {
    bool flag = false;

    for(int i = s + 1; i <= n; i++) {
        if(f[s] == 0) {
            break;
        }

        if(!flag && f[s] == 2) {
            flag = true;
        }

        if(flag && f[s] == 1) {
            ans++;
        }

        if(flag && f[s] > 1) {
            ans += (f[s] - 1);
            break;
        }
    }
}

int main () {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> T;

    while(T--) {
        memset(x, 0, sizeof(x));
        memset(f, 0, sizeof(f));
        ans = 0;

        cin >> n >> d;
        for(int i = 1; i <= n; i++) {
            cin >> x[i];
        }

        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(x[j] - x[i] <= d) {
                    f[i]++;
                }
            }
        }

        cout << n - f[1] - 1 << endl;
    }

    return 0;
}
