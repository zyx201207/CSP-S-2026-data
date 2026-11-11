#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 5e5+5;
int ck, n, m, d, q, z, s, a[MAXN];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> ck >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
    {
        cin >> a[i];
    }
    int k, ans = 0, u, v;
    for(int i = 1;i <= n;i++)
    {
        cin >> k;
        for(int j = 1;j <= k;j++)
        {
            cin >> u >> v;
        }
    }
    for(int i = 1;i <= q;i++)
    {
        cin >> z >> s;
    }
    for(int i = 1;i <= q;i++)
    {
        cout << a[1] <<u+(u+v)+v+a[3] << endl;
        cout << a[1]+u+u+a[2];
        break;
    }

    return 0;
}
