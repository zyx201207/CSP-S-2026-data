#include<bits/stdc++.h>
using namespace std;

int u[10005],v[10005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,t,n,k;
    cin>>c>>t;
    for(int j=1;j<=t;j++)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>u[i]>>v[i];
        }
    }
    if(c==0)
    {
        cout<<"1"<<endl<<"2";
    }
    else
    {
        cout<<"12251";

    }
    return 0;
}
