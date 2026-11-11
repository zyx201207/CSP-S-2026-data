#include <bits/stdc++.h>
#define int long long
#define loop(a,b) for (register int a = 1 ; a <= b ; ++a)
#define lop(a,b,c) for (register int a = b ; a <= c; ++a)
using namespace std;
vector<pair<int,int>> a[500005];
int b[505][505],c[500005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    int T,n,m,d,q;
    int k,c1,c2;
    cin >> T >> n >> m >> d >> q;
    loop(i,m) cin >> c[i];
    loop(i,n)
    {
        cin >> k;
        loop(j,k)
        {
            cin >> c1 >> c2;
            a[c1].push_back({i,c2});
        }
    }
    memset(b,0x3f,sizeof(b));
    loop(i,m)
    {
        k=a[i].size();
        lop(x,0,k-1)
        {
            lop(y,x+1,k-1)
            {
                b[a[i][x].first][a[i][y].first]=b[a[i][y].first][a[i][x].first]=min(a[i][x].second+a[i][y].second,b[a[i][y].first][a[i][x].first]);
            }
        }
    }
    loop(k,n)
    {
        loop(i,n)
        {
            if (i==k||b[i][k]>4557430888798830399ll) continue;
            loop(j,n)
            {
                if (k==j||i==j) continue;
                if (b[i][k]+b[k][j]<b[i][j])
                {
                    b[i][j]=b[i][k]+b[k][j];
                }
            }
        }
    }
    loop(i,n) b[i][i]=0;
    while (q--)
    {
        int x,y,res=LONG_LONG_MAX;
        cin >> x >> y;
        for (auto i : a[x])
        {
            for (auto j : a[y])
            {
                res=min(res,b[i.first][j.first]+i.second+j.second);
            }
        }
        cout << res+c[x]+c[y] << endl;
    }
    return 0;
}
