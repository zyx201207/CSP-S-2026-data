#include<bits/stdc++.h>
using namespace std;
int a[109];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    int n,m;
    cin>>c>>t>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    m=n/2-1;
    cout<<m;
    return 0;
}
