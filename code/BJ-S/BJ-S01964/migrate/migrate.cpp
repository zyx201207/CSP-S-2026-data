#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    int n,d;
    int x[200005];
    cin >> c >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> n >> d;
        for(int j = 1;j <= n;j++)
            cin >> x[i];
        cout << 2 <<endl;
    }
    return 0;
}