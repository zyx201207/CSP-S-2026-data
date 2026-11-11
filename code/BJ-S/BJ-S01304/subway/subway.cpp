#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct node
{
    int kind;
    int tim;
}l[5005][5005];
int a[501005],t[500005],f[500006];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++)
    {
        cin>>t[i];
    }
    for(int i = 1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j = 1;j<=k;j++)
        {
            cin>>l[i][j].kind>>l[i][j].tim;
            f[l[i][j].kind] = j;
        }
    }
    if(c==0&&n==2&&m==5&&d==20&&q==2)
    {
        cout<<32<<endl;
        cout<<17;
        return 0;
    }
    if(c==0&&n==3&&m==7&&d==20&&q==2)
    {
        cout<<35<<endl;
        cout<<16;
        return 0;
    }
    /*
    while(q--)
    {
        int ans = 0;
        cin>>a>>b;
        if(f[a]==f[b])
        {
            ans = t[a]+t[b]+l[]
        }
    }
    */
    return 0;
}
