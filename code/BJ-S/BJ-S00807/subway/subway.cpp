#include <bits/stdc++.h>
using namespace std;
int c, m, n, d, q,w[500005],k[1010],x[100005],y[100005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> m >> n >> d >> q;
    for (int i = 1;i <= m;i++)
        cin >> w[i];
    for (int i = 1;i <= 2*n;i++)
        cin >> k[i];
    for (int i = 1;i<= q;i++)
        cin >> x[i] >> y[i];

    return 0;
}