#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i=1;i<=n-1;i++) cin >> u >> v;
        if (k==n)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            cout << (n/2-k+2)/4+1 << endl;
        }
    }
    return 0;
}