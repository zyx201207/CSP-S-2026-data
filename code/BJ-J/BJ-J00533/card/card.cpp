#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e5 + 10;

int n, m;
int a[N];
int now[N];
int nxt[N];
int jump[N][25];
int cnt[N];

signed main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];

        nxt[now[a[i]]] = i;

        now[a[i]] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        jump[i][0] = nxt[i];
    }

    for(int j = 1; j <= 20; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        int s = i;

        while(s <= n)
        {
            for(int j = 20; j >= 0; j--)
            {
                if(jump[s][j])
                {
                    s = jump[s][j];
                }
            }

            cnt[a[s]]++;

            s++;
        }
    }

    for(int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }

    return 0;
}