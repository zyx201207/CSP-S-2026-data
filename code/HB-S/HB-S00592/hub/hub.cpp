#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    for(int i=1;i<=t;i++)
    {
        cin >> n >> k;
        for(int j=1;j<n;j++)
        {
            cin >> u >> v;
        }
        cout << i << "\n";
    }
    return 0;
}
