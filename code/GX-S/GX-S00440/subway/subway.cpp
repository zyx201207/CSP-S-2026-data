#include <bits/stdc++.h>
using namespace std;
struct dt{
    int z;
    int t;
};

int main()
{
    freopen("subwayin","r",stdin);
    freopen("subwayout","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int a[m+1];
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    dt s[n+1][d+1];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>s[i][j].z>>s[i][j].t;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=2;j++)
            cout<<s[i][j].z>>s[i][j].t;

}



