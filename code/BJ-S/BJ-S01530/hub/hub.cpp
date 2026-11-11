#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    int c , t;
    cin >> c >> t;
    while (t--)
    {
        int n , k;
        cin >> n >> k;
        // if (c == 13 || c == 14)
        // {
            cout << (n / 2 - k + 2) / 4 + 1 << endl;
        // }
    }
    return 0;
}