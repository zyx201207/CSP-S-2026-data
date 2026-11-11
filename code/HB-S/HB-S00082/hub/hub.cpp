#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t;
    cin >> c >> t;
    int n[t+1],k[t+1];
    int u[t+1][10^6],v[t+1][10^6];
    for(int i=1;i<=t;i++)
    {
        cin >> n[i] >> k[i];
        for(int j=1;j<=n[i];i++)
        {
            cin >> u[i][j],v[i][j];
        }
    }

    return 0;
}
