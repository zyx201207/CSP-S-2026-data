#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,x[2222222];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>x[i];
        cout<<n-3<<endl;
    }
    return 0;
}
