#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define endl '\n'
using namespace std;
typedef long long ll;

int main(int argc, char* argv[]) {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int cse{}, times{};
    cin >> cse >> times;
    while (times--) {
        int n{}; ll len{};
        cin >> n >> len;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> dis(n, vector<int>(n, int(1e9))), cnt(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (a[j] - a[i] <= len) {
                dis[i][j] = cnt[i][j] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;
        }
        for (int k = 0; k < n; k++)
        for (int i = 0; i < k; i++)
        for (int j = k + 1; j < n; j++) {
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            if (dis[i][j] == dis[i][k] + dis[k][j]) {
                cnt[i][j] += cnt[i][k] * cnt[k][j];
            } else if (dis[i][j] > dis[i][k] + dis[k][j]) {
                cnt[i][j] = 1, dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            ans += (cnt[i][j] == 2);
        }
        cout << ans << endl;
    }
    return 0;
}