#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200005];
bool mark[200005][35];
bool f[200005];
int cnt[35];

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int k = a[i];
        for(int j = 0; j <= 30; j++)
        {
            if((k >> j) & 1)
            {
                mark[i][j] = true;
                cnt[j]++;
            }
        }
    }
    int sum = 0;
    bool fg = false;
    queue<int> q;
    for(int j = 30; j >= 0; j--)
    {
        if(cnt[j] < m)
        {
            continue;
        }
        if(!fg)
        {
            for(int i = 1; i <= n; i++)
            {
                if(mark[i][j])
                {
                    q.push(i);
                }
            }
            sum += (1 << j);
            fg = true;
            continue;
        }
        int cnt = 0;
        int p = q.size();
        for(int i = 1; i <= p; i++)
        {
            int x = q.front();
            q.pop();
            q.push(x);
            if(mark[x][j])
            {
                cnt++;
            }
        }
        if(cnt < m)
        {
            continue;
        }
        p = q.size();
        for(int i = 1; i <= p; i++)
        {
            int x = q.front();
            q.pop();
            if(mark[x][j])
            {
               q.push(x);
            }
        }
        sum += (1 << j);
    }
    cout << sum << "\n";
    return 0;
}