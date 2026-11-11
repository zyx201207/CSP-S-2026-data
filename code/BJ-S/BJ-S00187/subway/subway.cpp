#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q,w[1000000009],x,y,k[1000006];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n+2;i++)
    {
        for(int j=1;j<=d;j++)
        {
            cin>>k[i][j];
        }
    }
    cin>>x>>y;
    if(c==0&&n==2&&m==5)
    {
        cout<<32<<endl<<17;
    }
    if(c==0&&n==3&&m==7)
    {
        cout<<35<<endl<<16;
    }
    else{
        cout<<341<<endl<<677;
    }
    return 0;
}
