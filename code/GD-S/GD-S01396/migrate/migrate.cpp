#include <bits/stdc++.h>
#define int ll
#define fi first
#define endl '\n'
#define se second
#define il inline
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e6 + 10;
int n, d, ans, a[N], L[N], R[N], LL[N], RR[N], RL[N], LR[N], f[400][400], g[400][400];
vector<pii> vec;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int Cas, T;
    cin >> Cas >> T;
    while (T--)
    {
        cin >> n >> d, vec.clear(), ans = 0, a[0] = -INF, a[n + 1] = INF;
        for (int i = 1; i <= n; i++)
            cin >> a[i], LR[i] = RL[i] = 0;
        if (n > 300)
        {
            for (int i = 1, j = 1, k = 1; i <= n; i++)
            {
                while (a[i] - a[j] > d)
                    j++;
                if (a[i] - a[i - 1] > d)
                    k = i;
                L[i] = j, LL[i] = k, RL[j] = (RL[j] ? RL[j] : i);
            }
            for (int i = n, j = n, k = n; i >= 1; i--)
            {
                while (a[j] - a[i] > d)
                    j--;
                if (a[i + 1] - a[i] > d)
                    k = i;
                R[i] = j, RR[i] = k, LR[j] = (LR[j] ? LR[j] : i);
            }
            for (int i = 1; i < n; i++)
                if (L[i + 1] < i && R[i] > i + 1 && R[L[i + 1]] == i + 1 && L[R[i]] == i)
                    vec.pb({L[i + 1], R[i]});
            for (int i = 0; i < vec.size(); i++)
            {
                int l = vec[i].fi, r = vec[i].se;
                int x = max(LL[l], (i ? vec[i - 1].fi + 1 : 1)), y = min(RR[r], (i < vec.size() - 1 ? vec[i + 1].se - 1 : n));
                ans += (LR[R[l]] - x + 1) * (y - RL[L[r]] + 1);
            }
            cout << ans << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = 0, g[i][j] = INF;
        for (int i = 1; i <= n; i++)
        {
            g[i][i] = 0, f[i][i] = 1;
            for (int j = i - 1; a[i] - a[j] <= d; j--)
                for (int k = 1; k <= j; k++)
                    g[i][k] = min(g[i][k], g[j][k] + 1);
            for (int j = i - 1; a[i] - a[j] <= d; j--)
                for (int k = 1; k <= j; k++)
                    if (g[i][k] == g[j][k] + 1)
                        f[i][k] += f[j][k];
            for (int j = 1; j <= i; j++)
                ans += ((f[i][j] = min(f[i][j], 3ll)) == 2);
        }
        cout << ans << endl;
    }
    return 0;
}