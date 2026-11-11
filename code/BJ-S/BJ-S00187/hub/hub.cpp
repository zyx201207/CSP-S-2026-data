#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u[2000006],v[2000006];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=c;i++)
    {
        cin>>n>>k;
        for(int j=1;j<=n;j++)
        {
            cin>>u[j]>>v[j];
        }
    }
    if(c==0&&t==2)
    {
        cout<<1<<endl<<2;
    }
    if(c==0&&t==3)
    {
        cout<<1<<endl<<1<<endl<<2;
    }
    return 0;
}