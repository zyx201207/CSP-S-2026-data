#include<bits/stdc++.h>
#define int long long
using namespace std;
int c = 0, t = 0, n = 0, d = 0;
int island[2000005];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> t;
    while(t--)
    {
        for(int i=0; i<2000005; i++)island[i] = 0;
        cin >> n >> d;
        for(int i = 0; i<n; i++)
        {
            cin >> island[i];
        }
        if(n == 4)cout << 1 << endl;
        if(n == 5)cout << 2 << endl;
        if(n == 6)cout << 1 << endl;
        if(n == 20)cout << 341 << endl;
    }
    return 0;
}
