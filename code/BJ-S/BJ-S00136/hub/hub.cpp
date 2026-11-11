#include <cstdio>
#include <iostream>
using namespace std;

int c, t, n, k, u, v;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> t;
    int ans = 1e18;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1;i <= n-1;i++)
        {
            cin >> u >> v;
            ans = min(abs(v-u), ans);
        }
        cout << ans << endl;
    }


    return 0;
}
