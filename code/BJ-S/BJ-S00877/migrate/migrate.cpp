#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> x;
        for (int i = 0; i < n; i++) {
            int idx;
            cin >> idx;
            x.push_back(idx);
        }
        int res = 0

        map<pair<int, int>, int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (x[j] - x[i] == d) ans[{i, j}] == 1;
                else if (x[j] - x[i] < d) ans[{i, j}] == 0;
                else {
                    if ((x[j] - x[i]) % d == 0) ans[{i, j}] == 1;
                    else {
                        for (int k = 1; k < d; k++)
                            if (x[j] - x[i] == 2 * d + k) ans[{i, j}] = 2, res++;
                    }
                }
             }
        }

        cout << res << endl;
    }

    return 0;
}
