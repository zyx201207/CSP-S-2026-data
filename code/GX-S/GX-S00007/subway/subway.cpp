#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int n, m, d, t;
int w[N];
int k[N];
int a[N];
int t[N][N];
bool mind[N];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int cccc;
    cin >> cccc;

    cin >> n >> m >> d >> t;
    for(int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> k[i];
        for(int l = 0; l < k[i]; l++)
        {
            int o, p;
            cin >> o >> p;
            a[o] = p;
        }
    }
    while(t--)
    {
        int x, y;
        cin >> x >> y;
        cout << w[x] + a[x] + a[y] + w[y];
    }
    return 0;
}
