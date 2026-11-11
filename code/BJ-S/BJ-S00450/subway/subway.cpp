#include<bits/stdc++.h>
using namespace std;
int n,m,q,oo,o2,o3,a[1510];
long long an[1510][1510];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>q>>n>>m>>q>>q;
    for(int i=1;i<=n+m;i++)
    {
        for(int j=1;j<=n+m;j++)
        {
            an[i][j]=9000000000000000000;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>oo;
        for(int j=1;j<=oo;j++)
        {
            cin>>o2>>o3;
            an[m+i][o2]=o3;
            an[o2][m+i]=o3;
        }
    }
    for(int i=1;i<=n+m;i++)
    {
        for(int j=1;j<=n+m;j++)
        {
            for(int k=1;k<=n+m;k++)
            {
                if(an[j][i]!=9000000000000000000&&an[i][k]!=9000000000000000000)an[j][k]=min(an[j][k],an[j][i]+an[i][k]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>o2>>o3;
        cout<<a[o2]+an[o2][o3]+a[o3]<<endl;
    }
    return 0;
}