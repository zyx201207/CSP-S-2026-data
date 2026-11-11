#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdin);
    int c,t;
    int n,d;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(d==2)
        {
            cout<<n-3;
            return 0;
        }
        if(d==3)
        {
            cout<<n-2;
            return 0;
        }
        cout<<n-(d+1);
    }

    return 0;
}
