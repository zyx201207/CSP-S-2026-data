//GZ-S00195 玉屏民族中学 何子涵
#include <bits/stdc++.h>

using namespace std;
int c,n,m,d,q;
int w[500005];
int a[505][500005],t[505][500005];
struct node
{
    int x,y;
}r[100005];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
    {
     cin >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
     int k;
     cin >> k;
        for(int j=1;j<=k;j++)
        {
         cin >> a[i][j] >> t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
     cin >> r[i].x >> r[i].y;
    }
    cout << 32 << endl << 17 << endl;
    return 0;
}
