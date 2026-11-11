#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

void quickio()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(NULL);
}

void sol()
{
    int n, d, ans = 0;
    cin >> n >> d;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<int> dis(5000000, INT_MAX);
    dis[0] = 0;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        auto now = q.top();
        q.pop();
        if (now.first > dis[now.second])
        {
            continue;
        }
        if (now.first == dis[now.second])
        {
            ans++;
        }
        if (now.second == n - 1)
        {
            continue;
        }
        for(int i = now.second;i < n;i ++)
        {
            if(now.second + d < x[i])
            {
                break;
            }
            int newdis = now.first + 1;
            dis[x[i]] = max(dis[x[i]],newdis);
            q.push(make_pair(newdis,x[i]));
        }
    }
    cout << ans << '\n';
}
int main()
{
    quickio();
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        sol();
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4 
5 2
1 2 3
*/