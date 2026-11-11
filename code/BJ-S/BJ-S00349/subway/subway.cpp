#include <bits/stdc++.h>
using namespace std;
int w[20005],a[20005],t[20005],x[20005],y[20005],xx[20005],yy[20005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];//依次表示从每个地铁站的地铁口走到站厅需要的时间
    }
    int pos=0;
    while(n--)
    {
        int k;
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>a[++pos]>>t[pos];//aij表示第i条线路经过的第j个地铁站tij表示从该地铁站的站厅走到第i条线路的站台需要的时间。
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int j=1;j<=q;j++)
    {
        for(int i=1;i<=pos;i++)
        {
            if(a[i]==x[j])xx[j]=i;
            if(a[i]==y[j])yy[j]=i;
        }
    }

    for(int j=1;j<=q;j++)
    {
        int sum=w[x[j]]+w[y[j]];
        for(int i=xx[j];i<=yy[j];i++)
        {
            sum+=t[i];
            cout<<sum<<endl;
        }
    }
    return 0;
}
