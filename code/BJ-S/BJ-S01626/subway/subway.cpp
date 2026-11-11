#include <iostream>
using namespace std;

int w[500010];
int a[500010],t[500010],a1[500010],t1[500010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >>c >>n >>m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    long long ans = 0;
    for (int j = 2; j <= n +2; j++)
    {
        int k;
        cin >>k;
        for (int i = 1; i <= 2 *k; i++)
        {
            cin >> a[i] >> t[i];
            ans += t[i];
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        ans += w[x] + w[y];
        cout << ans << endl;
    }
    return 0;
}