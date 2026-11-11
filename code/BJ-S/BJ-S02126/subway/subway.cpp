#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int w[505],k[5005],c;
int a[505][500005], t[505][500005],b[505][25], cntb[25], ls[505][505],K[505][505],f=1;
void node()
{
    for(int i = 1;i <= 501;i++)
    {
        if(a[2][1] == 1)cout << i << endl;
        for(int j = 1;j <= cntb[i];j++)
        {
            for(int T = 1;T <= k[b[i][j]];T++)
            {
                int ls1 = w[i] + t[b[i][j]][T]+t[b[i][j]][K[b[i][j]][i]] + w[a[b[i][j]][T]];
                if(ls1 < ls[i][a[b[i][j]][T]]&&ls[b[i][j]][a[j][T]] != 0);
                {
                    ls[i][a[b[i][j]][T]] = ls1;
                    ls[a[b[i][j]][T]][i] = ls1;
                    //if(f[1] == 0&&i == 3)cout << a[b[i][j]][T] << " ";
                    //if(f[1] == 1&&i == 3)cout << a[b[i][j]][T] << endl;
                }
            }
        }
        //if(i ==3)cout << f[1];
        //if(a[2][1] == 1)cout << i << endl;

    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)
        {
            cin >> a[i][j] >> t[i][j];
            cntb[a[i][j]]++;
            b[a[i][j]][cntb[a[i][j]]]= i;
            K[i][a[i][j]] = j;
        }
    }
    node();
    for(int i = 1;i <=501;i++)
    {
        for(int j = i;j <= 501;j++)
        {
            if(ls[i][j] == 0&&i != j)
            {
                f=1;
                for(int T = 1;T <= 501;T++)
                {
                    if(ls[i][T] > 0&&ls[T][j] > 0)
                    {
                        int ls1 = ls[i][T] + ls[T][j] - 2*w[T];
                        if(ls1 < ls[i][j]||f == 1)
                        {
                            ls[i][j] = ls1;
                            f = 0;
                        }
                    }
                }
            }
        }
    }
    int x, y;
    for(int i = 1;i <= q;i ++)
    {
        cin >> x >> y;
        cout << ls[x][y] << endl;
    }
}
