#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;
ll ans[5005][5005],a[2000005],cnt[5005][5005];
ll n,D;
struct node
{
    ll x,d;
};
void bfs(ll st)
{
    queue<node> q;
    q.push({st,0});
    while (!q.empty())
    {
        ll x = q.front().x,d = q.front().d;
        //cout << x << ' ' << d <<"\n";
        q.pop();
        for (ll nx = x+1;nx <= n;nx++)
        {
            if (a[nx] - a[x] > D) break;
            if (1ll + d > ans[st][nx]) continue;
            if (ans[st][nx] > 1ll + d) cnt[nx][st] = cnt[st][nx] = 0;
            ans[st][nx] = 1 + d;
            cnt[nx][st]++;
            cnt[st][nx]++;
            q.push({nx,ans[st][nx]});
        }
        for (ll nx = x-1;nx >= 1;nx--)
        {
            if (a[x] - a[nx] > D) break;
            if (1ll + d > ans[st][nx]) continue;
            if (ans[st][nx] > 1ll + d) cnt[nx][st] = cnt[st][nx] = 0;
            ans[st][nx] = 1ll + d;
            cnt[nx][st]++;
            cnt[st][nx]++;
            q.push({nx,ans[st][nx]});
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin >> c >> T;
    if (c == 11 || c == 12)
    {
        while (T--)
        {
            cin >> n >> D;
            ll d;
            for (ll i = 1;i <= n;i++) cin >> a[i];
            if (n != 1) d = a[2] - a[1];
            if (D <= d)
            {
                cout << "0\n";
                continue;
            }
            D /= d;
            D *= 2;
            ll ans = max(0ll,n-D+1);
            cout << ans << "\n";
        }
        return 0;
    }
    while (T--)
    {
        memset(ans,0x7f,sizeof(ans));
        memset(cnt,0,sizeof(cnt));
        cin >> n >> D;
        for (ll i = 1;i <= n;i++) cin >> a[i];
        for (ll i = 1;i <= n;i++)
        {
            bfs(i);
        }
        ll anss = 0;
        for (ll i = 1;i <= n;i++)
        {
            for (ll j = i+1;j <= n;j++)
            {
                if (cnt[i][j] == 2)
                {
                    cout << i << ' ' << j << "\n";
                    anss++;
                }
            }
        }
        cout << anss << "\n";
    }
    return 0;
}
