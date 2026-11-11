#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 502, M = 1e6 + 6, NM = 1503, QQQ = 1e5 + 5;

ll c, n, m, d, nq, w[M], k[M], dis[NM][NM], que1[QQQ], que2[QQQ];
vector<ll> a[M], t[M];

struct stro
{
    ll to, w;
};
vector<stro> oo[M];

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> c >> n >> m >> d >> nq;
    for (ll i = 1; i <= m; i++) cin >> w[i];
    ll tmpa, tmpt;
    for (ll i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (ll j = 1; j <= k[i]; j++)
        {
            cin >> tmpa >> tmpt;
            a[i].push_back(tmpa);
            t[i].push_back(tmpt);
        }
    }

    for (ll i = 1; i <= nq; i++)
    {
        cin >> que1[i] >> que2[i];
    }

    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k[i]; j++)
        {
            oo[a[i][j]].push_back({i, t[i][j]});
        }
    }

    for (int i = 1; i <= m; i++)
    {
        if (oo[i].empty()) continue;
        for (int j = 0; j < oo[i].size(); j++)
        {
            for (int l = j + 1; l < oo[i].size(); l++)
            {
            	ll tmp = oo[i][j].w + oo[i][l].w;
                if (dis[oo[i][j].to][oo[i][l].to] > tmp)
                {
                    dis[oo[i][j].to][oo[i][l].to] = tmp;
                    dis[oo[i][l].to][oo[i][j].to] = tmp;
                }
            }
        }
    }
    for (ll l = 1; l <= n; l++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (dis[i][l] + dis[l][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][l] + dis[l][j];
                }
            }
        }
    }

    for (int i = 1; i <= nq; i++)
    {
        ll ans = 1e18;
        int u = que1[i], v = que2[i];
        for (int j = 0; j < oo[u].size(); j++)
        {
            for (int l = 0; l < oo[v].size(); l++)
            {
                ans = min(ans, oo[u][j].w + oo[v][l].w + dis[oo[u][j].to][oo[v][l].to]);
            }
        }
        cout << ans + w[u] + w[v] << "\n";
    }

    return 0;
}
