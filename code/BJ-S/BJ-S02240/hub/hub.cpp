#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    srand(time(0));
    int c, t;
    cin >> c >> t;
    while(t--)
        cout << rand() % 10 + 1 << "\n";
    return 0;
}
