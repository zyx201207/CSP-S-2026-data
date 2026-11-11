#include <bits/stdc++.h>
using namespace std;

long long mp[1010][1010];
long long c,T,n,k;

int main ()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> T;
    while(T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            int u,v;
            cin >> u >> v;
            mp[u][v] = 1;
            mp[v][u] = 1;
        }
        if (k == 2)
        {
            cout << 1 << endl;
            continue;
        }
    }
    return 0;
}