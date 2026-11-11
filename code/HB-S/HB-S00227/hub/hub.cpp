#include <bits/stdc++.h>
using namespace std;

int c,t,n,k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>t;
    while (t--)
    {
        cin>>n>>k;
        cout<<n/k/2<<endl;
        for (int i = 0; i < n-1; i++)
            cin>>n>>k;
    }

    return 0;
}