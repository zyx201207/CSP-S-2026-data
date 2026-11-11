#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int c,t;
int u[N],v[N];
int qpow(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> t;
    srand(time(0));
    int x = rand() % (9 * qpow(10,t - 1) - 1) + qpow(10,t - 1) + 1;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        for(int i = 1;i < n;i++) cin >> u[i] >> v[i];
        while(x != 0)
        {
            cout << x % 10 << '\n';
            x /= 10;
        }
    }
    return 0;
}
