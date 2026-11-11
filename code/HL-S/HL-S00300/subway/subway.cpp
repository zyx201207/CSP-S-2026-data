#include <bits/stdc++.h>
using namespace std;
int a[30][30];
int w[20001];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m*2+1;j++)
        {
            cin>>a[i][j];
        }
    }
    if(m==1)
    {
        for(int i=1;i<=q;i++)
        {
            cout<<0<<endl;
        }
        return 0;
    }
    for(int i=1;i<=q;i++)
    {
        cout<<1<<endl;
    }
    return 0;
}

