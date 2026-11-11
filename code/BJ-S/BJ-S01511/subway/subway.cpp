#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int N = 5e3 + 10;
const int M = 5e5 + 10;

ll w[M];
ll f[N][N];
struct node
{
    int to;
    ll len;
    friend bool operator < (node p,node q)
    {
        return p.to < q.to;
    }
};
vector<node> a[N];
vector<node> g[M];

void add(int i,int j)
{
    int x = 1,y = 1;
    while(x < a[i].size() && y < a[j].size())
    {
        if(a[i][x].to < a[j][y].to) x++;
        else if(a[i][x].to > a[j][y].to) y++;
        else
        {
            if(a[i][x].len + a[j][y].len < f[i][j])
            {
                f[i][j] = a[i][x].len + a[j][y].len;
                f[j][i] = a[i][x].len + a[j][y].len;
            }
            x++;
            y++;
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            f[i][j] = 1e18;
        f[i][i] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        a[i].push_back({0,0ll});
        for(int j = 1; j <= t; j++)
        {
            a[i].push_back({0,0ll});
            cin >> a[i][j].to >> a[i][j].len;
            g[a[i][j].to].push_back({i,a[i][j].len});
        }
        sort(a[i].begin(),a[i].end());
        for(int j = 1; j < i; j++)
            add(i,j);
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(f[i][k] == 1e18 || i == k) continue;
            for(int j = 1; j <= n; j++)
                if(f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k] + f[k][j];
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        ll ans = 1e18;
        for(int i = 0; i < g[x].size(); i++)
        {
            for(int j = 0; j < g[y].size(); j++)
                ans = min(ans,g[x][i].len + g[y][j].len + f[g[x][i].to][g[y][j].to]);
        }
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}
//O(qd^2 + n^3 + nm)
