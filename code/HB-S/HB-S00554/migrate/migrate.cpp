#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int k=d/(a[1]-a[2]);
        cout<<k<<'\n';
    }
}