#include <bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    for (int i = 1;i <= t;i++)
    {
        int n,k;
        bool flag = true;
        int a[1000006];
        cin >> n >> k;
        for (int j = 1;j <= n;j++)
        {
            int u,v;
            cin >> u >> v;
            a[u] = v;
        }
        for (int j = 1;j <= n;j++)
        {
            if (a[i] != i + 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << k / 2 + 1 << endl;
        }
        else
        {
            cout << k / 3 + 1 << endl;
        }
    }
    return 0;
}
