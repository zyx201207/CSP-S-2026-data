#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[500005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    int ans=0;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        cout<<x[n]<<d;
        ans=(x[n]-(d-1)*2)/2;
        cout<<ans;
    }
    return 0;
}
