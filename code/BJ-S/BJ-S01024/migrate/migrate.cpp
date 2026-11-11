#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int c,t;
int x[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        int n,d;
        cin >> n >> d;
        int cnt = 0;
        for(int i = 1;i <= n;i++) cin >> x[i];
        if(d <= n && d % (x[2] - x[1]) == 0) cout << n - 3 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}
