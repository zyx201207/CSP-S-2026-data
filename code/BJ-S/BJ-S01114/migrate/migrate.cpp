#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int C, T;
    int n, d;
    int x[N];
    int path[N][N];
    int len[N][N];
    cin >> C >> T;

    for (int G = 1; G <= T; G++) {
        memset(path, 0, sizeof(path));
        memset(len, 127, sizeof(len));
        cin >> n >> d;
        for (int j = 1; j <= n; j++){
            cin >> x[j];
            path[j][j] = 1;
            len[j][j] = 0;
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 1; i + l - 1 <= n; i++) {
                int j = i + l - 1;
                if (x[j] - x[i] <= d) {
                    path[i][j] = 1;
                    len[i][j] = 1;
                    continue;
                }

                for (int k = i + 1; k <= j - 1; k++) {
                    if (x[j] - x[k] > d || x[k] - x[i] > d) continue;
                    if (len[i][j] == len[i][k] + len[k][j]) {
                        path[i][j] += path[i][k] * path[k][j];
                    }
                    else if (len[i][j] > len[i][k] + len[k][j]) {
                        len[i][j] = len[i][k] + len[k][j];
                        path[i][j] = 1;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (path[i][j] == 2) ans++;
            }
        }

        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
