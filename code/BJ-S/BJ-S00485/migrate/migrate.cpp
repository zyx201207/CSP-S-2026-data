#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 2e6;
const int INF = 1e9;

ll x[N + 5];
int deg[N + 5];
int dist[N + 5], cnt[N + 5];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c, t;
    cin >> c >> t;

    while (t--)
    {
        int n;
        ll d;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> x[i];

        ll ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; ++j)
            {
                deg[j] = 0;
                dist[j] = INF;
                cnt[j] = 0;
            }

            for (int u = i; u <= n; ++u)
                for (int v = u + 1; v <= n && x[v] - x[u] <= d; ++v)
                    ++deg[v];
            
            queue<int> q;
            q.push(i);
            cnt[i] = 1;
            dist[i] = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                if (cnt[u] == 2) ++ans;

                for (int v = u + 1; v <= n && x[v] - x[u] <= d; ++v)
                {
                    if (dist[u] + 1 == dist[v])
                    {
                        cnt[v] += cnt[u];
                    }
                    else if (dist[u] + 1 < dist[v])
                    {
                        dist[v] = dist[u] + 1;
                        cnt[v] = cnt[u];
                    }

                    --deg[v];
                    if (!deg[v]) q.push(v);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}