#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
int x[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        int n,d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        ll ans = 0;
        int dx = x[2] - x[1];
        int fmax = d / dx;
        for(int i = fmax + 1; i <= fmax * 2 - 1; i++)
        {
            ans += n - i;
        }
        cout << ans << endl;
    }
    return 0;
}
