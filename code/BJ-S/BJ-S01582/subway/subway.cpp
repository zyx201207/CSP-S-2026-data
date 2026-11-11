#include<iostream>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c, n, m, d, q,w[500005],a,x[505],y[505],k,l;
    cin >> c >> n >> m >> d >> p;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a;
        for(int j=1;j<=a*2;j++)
        {
            cin >> x[i] >> y[i];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin >> k >> l;
        cout << w[k]+w[l]+y[k]+y[l];
    }
}