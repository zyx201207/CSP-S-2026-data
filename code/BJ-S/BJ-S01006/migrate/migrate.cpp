#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll c,t,n,d;
ll x[2000005];
ll dis[5005][5005];
ll cnt[5005][5005];

struct bird
{
    ll s;
    ll now;
    ll len;
};

queue<bird> q;

inline void bfs()
{
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    for(int i = 1;i < n;i++)
    {
        q.push((bird){i,i,0});
    }
    while(!q.empty())
    {
        bird xx = q.front();
        ll s = xx.s,now = xx.now,len = xx.len;
        q.pop();
        if(dis[s][now] < len)
        {
            continue;
        }
        if(dis[s][now] == len)
        {
            cnt[s][now]++;
        }
        if(dis[s][now] > len)
        {
            dis[s][now] = len;
            cnt[s][now] = 1;
        }
        int i = now + 1;
        while(abs(x[i] - x[now]) <= d && i <= n)
        {
            q.push((bird){s,i,len + 1});
            i++;
        }
    }
    return;
}

ll cot = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
        {
            cin >> x[i];
        }
        bfs();
        cot = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                if(cnt[i][j] == 2)
                {
                    cot++;
                }
            }
        }
        cout << cot << endl;
    }


    return 0;
}
