#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m],k[n][2*m-1],t[n][m];
    for (int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for (int i=1;i<=n;i++)
    {
        int ki;
        cin>>ki;
        for (int j=1;j<=2*ki;j++)
        {
            cin>>k[i][j];
        }
    }
    for (int i=1;i<=q;i++)
    {
        int x,y,sum=0;
        cin>>x>>y;

        cout<<sum;
    }
    return 0;
}