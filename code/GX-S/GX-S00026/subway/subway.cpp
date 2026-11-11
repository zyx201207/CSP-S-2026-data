#include<bits/stdc++.h>
using namespace std;
int side[1005][1005], len[1005], vis[1005];
pair<int,int> si[1005];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(side, 0x3f, sizeof(side));
    int n, m, q;
    cin >> n >> n >> m >> q >> q;
    for(int i = 1; i <= m; i++) cin >> len[i];
    while(n--)
    {
        int nn;
        cin >> nn;
        for(int i = 1; i <= nn; i++)
        {
            int a, t;
            cin >> a >> t;
            si[i] = {a,t};
        }
        for(int l = 1; l < nn; l++)
            for(int r = l+1; r <= nn; r++)
            {
                side[si[l].first][si[r].first] = side[si[r].first][si[l].first] = min(side[si[l].first][si[r].first], si[l].second+si[r].second);
            }
    }
    /*for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << side[i][j] << ' ';
        }
        cout << endl;
    }*/
    while(q--)
    {
        memset(vis, 0x3f, sizeof(vis));
        int s, f;
        cin >> s >> f;
        queue<int>q;
        vis[s] = 0;
        q.push(s);
        while(q.size())
        {
            int x = q.front();
            q.pop();
            for(int i = 1; i <= m; i++)
            {
                if(side[x][i] != 0x3f3f3f3f && (vis[i] == 0x3f3f3f3f || vis[i] > side[x][i]+vis[x]))
                {
                    vis[i] = min(vis[i], side[x][i]+vis[x]);
                    q.push(i);
                }
            }
        }
        cout << vis[f]+len[s]+len[f] << endl;
    }
    return 0;
}
