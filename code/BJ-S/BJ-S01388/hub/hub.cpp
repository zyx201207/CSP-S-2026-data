#include <bits/stdc++.h>
using namespace std;
long long c,t,n,k,v[500005],u[500005];
bool flag = true;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> k;
        for (int i = 1;i < n;i++) cin >> u[i] >> v[i];
        if (n == k) cout << 0 << '\n';
        else if(n == 2) cout << 0 << '\n';
        else
        {
            cout << (n - 1) / k << '\n';
        }
    }
    return 0;
}
