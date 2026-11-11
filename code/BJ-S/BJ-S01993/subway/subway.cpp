#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[1010];
int a[510][1010];
int t[510][1010];
int x,y;
vector <int> in[1010];
vector <int> g[510];

int dfs (int x,int sum,int minn)
{
    if (x == y)
    {
        minn = min (minn,sum);
        return 0;
    }
    for (int i : in[x])
    {
        sum += t[i][x];
        int y = x;
        if (g[i][1] == x) x = g[i][2];
        else x = g[i][1];
        sum += t[i][x];
        dfs (x,sum,minn);
        sum -= t[i][y];
        sum -= t[i][x];
    }
    return minn;
}


int main ()
{
    freopen ("subway.in","r",stdin);
    freopen ("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> a[i][j] >> t[i][j];
            if (k == 1) break;
            in[j].push_back (i);
            g[i][j] = a[i][j];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        cout << w[x] + dfs (x,0,0x3f3f3f3f) + w[y] << endl;
    }
    return 0;
}