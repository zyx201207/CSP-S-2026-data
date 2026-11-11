#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define fi first
#define se second

const int N = 510,M = 5e5+10,D = 30;

bool st;

int cid,n,m,d,q;
int w[M],k[N];
int id[M][D],t[M][D],K[M];
ll e[N][N];

bool ed;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> cid >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(int i=1,k,I;i<=n;i++)
    {
        cin >> k;
        while(k--)
        {
            cin >> I;
            id[I][K[I]] = i;
            cin >> t[I][K[I]];
            K[I]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            e[i][j] = 1e18;
        }
        e[i][i] = 0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int x=0;x<K[i];x++)
        {
            for(int y=x+1;y<K[i];y++)
            {
                int u=id[i][x],v=id[i][y];
                e[u][v] = min(e[u][v],(ll)t[i][x]+t[i][y]);
                e[v][u] = min(e[v][u],(ll)t[i][x]+t[i][y]);
                // cerr << u << ' ' << v << ' ' << e[u][v] << '\n';
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                e[i][j] = min(e[i][j],e[i][k] + e[k][j]);
            }
        }
    }
    for(int i=1,x,y;i<=q;i++)
    {
        cin >> x >> y;
        // cout << x << ' ' << y << '\n';
        ll ans=1e18;
        for(int U=0;U<K[x];U++)
        {
            int u=id[x][U];
            for(int V=0;V<K[y];V++)
            {
                int v=id[y][V];
                // cerr << "QAQ " << u << ' ' << v << ' ' << e[u][v] << '\n';
                ans = min(ans,e[u][v] + t[x][U] + t[y][V]);
            }
        }
        cout << ans+w[x]+w[y] << '\n';
    }
    // cerr << (&st-&ed)*1.0/1024/1024 << " MB\n";
}