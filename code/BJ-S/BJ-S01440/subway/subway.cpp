#include<iostream>
#include<vector>
using namespace std;
int w[500005], a[505][500005], t[505][500005], c, n, m, d, q, k, tgt, x, y, ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    vector<pair<int, int>> G(500005); //G[start].push_back({target, time})
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> k;
        for(int j = 1; j <= k; j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    while(q--){
        cin >> x >> y;
        ans = 0;
        ans += w[x] + w[y];
        for(int i = x; i <= y - 1; i++)
        {
            ans += t[i][i] + t[i][i + 1];
            //cout << t[i][i] << ' ' << t[i][i + 1] << '\n';
        }

        cout << ans << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
