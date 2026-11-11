#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
struct node
{
    int w;
    int t;
}a[500010][510];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i][1].w;
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int g,h;
            cin>>g>>h;
            a[g][i].t=h;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        cout<<a[x][1].w+a[x][1].t+a[y][1].t+a[y][1].w<<endl;
    }
    return 0;
}
