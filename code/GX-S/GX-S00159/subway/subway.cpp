#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,c,d,q,w[500005];
int zz[21][1005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int nn;
        cin >> nn;
        for(int j=1;j<=nn;j++)
        {
            int z;
            cin>>z;
            cin >> zz[i][z];
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {

        }
    }
    for(int k=1;k<=m;k++)
    {
        if(zz[1][k]!=0 && zz[2][k]!=0)
        {
            int s=zz[1][k]+zz[2][k];
        }
    }
    while(q--)
    {
        cin >> x >> y;
        for(int i=1;i<=n;i++)
        {
            if(zz[i][x]!=0 && zz[i][y]!=0)
            {
                cout << w[x]+w[y]+zz[i][x]+zz[i][y];
            }
            else
            {
                if(zz[1][x]!=0)
                    cout << w[x]+w[y]+zz[1][x]+zz[2][y]+s;
                else
                    cout << w[x]+w[y]+zz[2][x]+zz[1][y]+s;
            }
        }
    }
    return 0;
}
