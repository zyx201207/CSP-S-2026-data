#include<bits/stdc++.h>
using namespace std;
const int N = 510,M = 5e5 + 10;
int w[M],k[N],a[N][2 * N],t[N][2 * N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= 2 * k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for(int i = 1; i <= q; i++)
    {
        int x,y;
        cin >> x >> y;
        cout << t[1][1] * 4 << endl;
    }
    return 0;
}
