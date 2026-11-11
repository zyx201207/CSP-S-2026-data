#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e6 + 10;

ll d;
int c;
int t;
int n;
ll x[N];
int ans[N];
int dis[N];

int BFS(int s)
{
    for (int i = 1; i <= n; i++)
        ans[i] = 0;

    for (int i = 1; i <= n; i++)
        dis[i] = 2*N;

    dis[s] = 0;

    queue<int> q;

    while (!q.empty())
        q.pop();

    q.push(s);

    while (!q.empty())
    {
        int u = q.front();

        q.pop();

        for (int i = 1; i <= n; i++)
        {
            if ((ll)abs(x[i] - x[u]) <= d)
            {
                if (dis[i] == dis[u] + 1)
                {
                    ans[i]++;

                    q.push(i);
                }

                else if (dis[i] > dis[u] + 1)
                {
                    dis[i] = dis[u] + 1;

                    ans[i] = 1;

                    q.push(i);
                }
            }
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++)
        if (ans[i] == 2)
            res++;

    return res;
}

void solve()
{
    cin >> n >> d;

    for (int i = 1; i <= n; i++)
        cin >> x[i];

    int ans = 0;

    for (int i = 1; i <= n; i++)
        ans += BFS(i);
    
    ans /= 2;

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);

    cin >> c >> t;

    for (int i = 1; i <= t; i++)
        solve();

    return 0;
}