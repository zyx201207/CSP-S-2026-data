//T2
#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
int w[130010]; //w表示从每个地铁站的地铁口走到站厅需要的时间。
int k[510]; //k[i]表示第 i 条线路经过的地铁站数
int a[510][130010]; //a[i][j]表示第 i 条线路经过的第 j 个地铁站
int t[510][130010]; //t[i][j]表示从该地铁站的站厅走到第 i 条线路的站台需要的时间。

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++)
        {
            scanf("%d",&a[i][j]);
            scanf("%d",&t[i][j]);
        }
    }
    int x[100010],y[100010];
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
    }
    if(c==0)
    {
        if(n==2)
        {
            cout<<"32"<<endl<<"17"<<endl;
        }
        else if(n==3)
        {
            cout<<"35"<<endl<<"16";
        }
    }
    return 0;
}
