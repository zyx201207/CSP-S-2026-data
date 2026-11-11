#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[505][500005];
int t[505][500005];
int d;
int q;
int c;
int k[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    int x[q+1],y[q+1];
    int time[q+1];
    int w[m+5] = {0};
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
        }
    }
    for(int r = 1;r <= q;r++)
    {
        cin >> x[r] >> y[r];
    }
    for(int i = 1;i <= q;i++)
    {
        time[i] = w[i] + t[i][i] + t[i][i+1] + w[i+1];
        cout << time[i] << endl;
    }
    return 0;
}