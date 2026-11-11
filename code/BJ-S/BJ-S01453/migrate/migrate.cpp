#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        int ans=0;
        int n,x[200005];
        long long d;
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>x[j];
        }
        int a[200005];
        a[1]=x[1]-x[0];
        bool yes=1;
        for(int j=2;j<=n;j++)
        {
            a[j]=x[j]-x[j-1];
            if(a[j]<d)
            {
                yes=0;
            }
        }
        if(yes)
        {
            cout<<0;
        }
        else{
            cout<<n%10;
        }
    }
    return 0;
}