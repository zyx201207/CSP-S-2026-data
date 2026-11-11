#include <iostream>
using namespace std;
int w[100000];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++)
        {
            int a, b;
            cin >> a >> b;
        }
    }
    for(int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << w[x] + w[y] << endl;
    }
    return 0;
}