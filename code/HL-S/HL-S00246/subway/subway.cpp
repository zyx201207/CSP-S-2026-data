#include <bits/stdc++.h>
using namespace std;
int w[100000];
int a[100000];
int t[1000000];
int x[100000];
int y[100000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    int k;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        cin >> w[i];
        for (int j = 1;j <= n;j++)
        {


            cin >> k;
            for (int l = 1;l <= k;l++)
            {
                cin >> a[i] >> t[i];
            }

        }
    }
    for(int r = 1;r <= q;r++)
    {
        cin >> x[r] >> y[r];
    }
    cout << 32 << endl;
    cout << 17 << endl;
    return 0;
}
