#include<bits/stdc++.h>
using namespace std;
int w[500005];
int k[505], a[505][20005];
long long t[505][20005];
unordered_map<int, long long> mp[505];
vector<int> p[500005];
long long f[505][505];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++){
            cin >> a[i][j] >> t[i][j];
            mp[i][a[i][j]] = t[i][j];
            p[a[i][j]].push_back(i);
        }
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int l = 1; l <= k[i]; l++)
                if (mp[j][a[i][l]]){
                    f[i][j] = min(f[i][j], t[i][l] + mp[j][a[i][l]]);
                    f[j][i] = f[i][j];
                }
    for (int l = 1; l <= n; l++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                f[i][j] = min(f[i][j], f[i][l] + f[l][j]);
                f[j][i] = f[i][j];
            }
    while (q--){
        int x, y; cin >> x >> y;
        long long ans = LONG_LONG_MAX;
        for (auto i : p[x])
            for (auto j : p[y])
                ans = min(ans, f[i][j] + mp[i][x] + mp[j][y]);
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
