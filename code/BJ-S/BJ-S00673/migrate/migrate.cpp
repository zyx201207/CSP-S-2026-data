#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000007];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int k=a[2]-a[1];
        if(d/k==2)cout<<n-3<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}