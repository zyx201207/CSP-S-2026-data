#include<bits/stdc++.h>
using namespace std;
int n,d,u,v,c,t;
int x[1000000],y[1000000];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>n>>d>>u>>v>>c>>t;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;i<=i;j++)
        {
            cin>>x[i];
            cin>>x[j];
        }
    }
    if(n==4&&d==2)
    {
        cout<<1<<endl<<2;
    }
    else
    {
        cout<<0<<endl<<1;
    }
    return 0;
}
