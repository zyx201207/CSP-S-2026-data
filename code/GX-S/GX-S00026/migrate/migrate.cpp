#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        int n, d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        int m = d/(a[2]-a[1]);
        if(m > 2) cout << 0 << endl;
        if(m == 2) cout << n-3 << endl;
        if(m == 1) cout << n-2 << endl;
    }
    return 0;
}
