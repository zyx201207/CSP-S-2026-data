#include <bits/stdc++.h>
using namespace std;
const int N = 500020;
int c, n, m, d, q;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数
int w[N], k[N];
int ans;
struct TRIP
{
    int x, y;
};
vector < TRIP >qu;
vector < int >a[500];
vector < int >t[500];
int main()
{
    freopen( "subway.in", "r", stdin );
    freopen( "subway.out", "w", stdout );
    cin >> c >> n >> m >> d >> q;
    qu.resize( q + 10 );
    for( int i = 1; i <= m; i++ )
    {
        cin >> w[i];
    }
    for( int i = 1; i <= n; i++ )
    {
        cin >> k[i];
        a[i].resize( k[i] + 10 );
        t[i].resize( k[i] + 10 );
        for( int j = 1; j <= k[i]; j++ )
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for( int i = 1; i <= q; i++ )
    {
        cin >> qu[i].x >> qu[i].y;
    }
    if( c >= 7 && c <= 11 )
    {
        for( int l = 1; l <= q; l++ )
        {
            int truex, tix, tiy, truey;
            ans = w[qu[l].x] + w[qu[l].y];
            for( int i = 1; i <= n; i++ )
            {
                int tx = find( a[i].begin(), a[i].end(), qu[l].x ) - a[i].begin();
                int ty = find( a[i].begin(), a[i].end(), qu[l].y ) - a[i].begin();
                if( tx <= a[i].size() )
                {
                    truex = tx;
                    tix = i;
                }
                if( ty <= a[i].size() )
                {
                    truey = ty;
                    tiy = i;
                }
            }
            if( tix == tiy )
            {
                ans += t[tix][truex] + t[tiy][truey];
            }
        }
        cout << ans << "\n";
    }
    else{
       for( int l = 1; l <= q; l++ )
        {
            ans = w[qu[l].x] + w[qu[l].y];
            int tmp = ans;
            bool v1 = 0;
            int same[N];
            for( int i = 1; i <= n; i++ )
            {
                int fx = find( a[i].begin(), a[i].end(), qu[l].x ) - a[i].begin();
                int fy = find( a[i].begin(), a[i].end(), qu[l].y ) - a[i].begin();
                if( fx <= k[i] && fy <= k[i])
                {
                    ans += t[i][fx];
                    ans += t[i][fy];
                    v1 = 1;

                    break;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
