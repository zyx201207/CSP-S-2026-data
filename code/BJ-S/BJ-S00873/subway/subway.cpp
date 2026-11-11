#include<iostream>
#include<vector>
using namespace std;
#define int long long
const int N = 505;
const int M = 5e5 + 5;
const int inf = 1e18;

int c,n,m,d,q,w[M],f[N][N];
vector<pair<int,int> > v[M];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++)
    {
        int k; cin >> k;
        for(int j=1;j<=k;j++)
        {
            int a, t; cin >> a >> t;
            v[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i != j) f[i][j] = inf;
    for(int i=1;i<=m;i++)
        for(int j=0;j<v[i].size();j++)
            for(int k=0;k<j;k++)
            {
                int x = v[i][j].first, y = v[i][k].first;
                f[x][y] = f[y][x] = min(f[x][y],v[i][j].second+v[i][k].second);
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
    // for(int i=1;i<=n;i++,cout<<'\n')
    //     for(int j=1;j<=n;j++) cout << f[i][j] << " ";
    while(q--)
    {
        int x, y; cin >> x >> y; int ans = inf;
        for(int i=0;i<v[x].size();i++)
            for(int j=0;j<v[y].size();j++)
                ans = min(ans,f[v[x][i].first][v[y][j].first]+v[x][i].second+v[y][j].second);
        // cout << ans << '\n';
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}