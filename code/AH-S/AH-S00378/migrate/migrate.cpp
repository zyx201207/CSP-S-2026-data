#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c, t;
ll n, d;
ll x[N];
namespace c_le_6 {
    const int N1 = 3e2 + 5;
    int dis[N1][N1];
    int ans = 0;
    void make_gragh() {
        memset(dis, 0x3f, sizeof dis);
        for (int i = 1; i <= n; i++) {
            dis[i][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (x[i] - x[j] <= d) {
                    dis[i][j] = dis[j][i] = 1;
                }
            }
        }
    }
    void Floyd() {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        return ;
    }
    void work() {
        make_gragh();
        Floyd();
        ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                int cnt = 0;
                for (int k = 1; k <= n; k++) {
                    if (k == i || k == j) continue;
                    if (dis[i][k] + dis[k][j] != dis[i][j]) continue;
                    for (int l = 1; l <= n; l++) {
                        if (k == l) continue;
                        if (l == i || l == j) continue;
                        if (dis[i][k] == dis[i][l] && dis[k][j] == dis[l][j]) {
                            cnt++;
                        }
                    }
                }
                if (cnt == 2) {
                    ans++;
                    //cout << i << " " << j << "\n";
                }
            }
        }
        cout << ans << "\n";
    }

}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if (c <= 6) {
        while (t--) {
            cin >> n >> d;
            for (int i = 1; i <= n; i++) {
                cin >> x[i];
            }
            c_le_6::work();
        }
	}
	return 0;
}
