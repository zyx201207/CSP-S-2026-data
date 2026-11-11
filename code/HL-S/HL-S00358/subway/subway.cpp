#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[100000010], a[100000010], t[100000010];
long long sum;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int v = 1; v <= m; v++)
    {
        cin>>w[v];
    }
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++)
        {
            cin >> a[j] >> t[j];
        }
    }
    for(int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
    }
    return 0;
}
