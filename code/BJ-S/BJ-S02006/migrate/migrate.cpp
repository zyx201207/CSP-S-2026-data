#include<bits/stdc++.h>
using namespace std;
int a[(int)1e6+10];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<a[n]-a[1]+a[(n+1)/2]-m<<endl;
    }
    return 0;
}
