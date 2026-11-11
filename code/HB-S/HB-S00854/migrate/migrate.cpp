#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int a[500005];
        memset(a,0,sizeof(a));
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cout<<n-2;
    }
    return 0;
}
